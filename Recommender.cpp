#include "Recommender.h"
#include "SimilarityCalculator.h"

#include <map>
#include <algorithm>

Recommender::Recommender(RatingManager& rm)
    : ratingManager(rm) {}

std::vector<int> Recommender::recommend(int targetUserId, int topN) {

    std::vector<int> recommendations;

    auto targetRatings =
        ratingManager.getRatingsByUser(targetUserId);

    if (targetRatings.empty())
        return recommendations;

    std::map<int, int> movieScores;

    const auto& allRatings =
        ratingManager.getAllRatings();

    std::vector<int> processedUsers;

    for (const auto& rating : allRatings) {

        int otherUserId = rating.getUserId();

        if (otherUserId == targetUserId)
            continue;

        bool alreadyProcessed = false;

        for (int id : processedUsers) {
            if (id == otherUserId)
                alreadyProcessed = true;
        }

        if (alreadyProcessed)
            continue;

        processedUsers.push_back(otherUserId);

        auto otherRatings =
            ratingManager.getRatingsByUser(otherUserId);

        int similarity =
            SimilarityCalculator::calculate(
                targetRatings,
                otherRatings
            );

        if (similarity <= 0)
            continue;

        for (const auto& r : otherRatings) {

            bool alreadyWatched = false;

            for (const auto& t : targetRatings) {
                if (t.getMovieId() == r.getMovieId())
                    alreadyWatched = true;
            }

            if (!alreadyWatched) {
                movieScores[r.getMovieId()] += r.getScore();
            }
        }
    }

    std::vector<std::pair<int,int>> sorted(
        movieScores.begin(),
        movieScores.end()
    );

    sort(sorted.begin(), sorted.end(),
        [](auto& a, auto& b) {
            return a.second > b.second;
        });

    for (int i = 0;
         i < topN && i < sorted.size();
         i++) {

        recommendations.push_back(sorted[i].first);
    }

    return recommendations;
}
