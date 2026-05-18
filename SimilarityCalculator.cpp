#include "SimilarityCalculator.h"
#include <cmath>

int SimilarityCalculator::calculate(
    const std::vector<Rating>& user1,
    const std::vector<Rating>& user2
) {
    int similarity = 0;
    int common = 0;

    for (const auto& r1 : user1) {
        for (const auto& r2 : user2) {

            if (r1.getMovieId() == r2.getMovieId()) {
                similarity += (5 - abs(r1.getScore() - r2.getScore()));
                common++;
            }
        }
    }

    if (common == 0)
        return -100;

    return similarity;
}
