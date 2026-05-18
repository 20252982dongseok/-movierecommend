#include "RatingManager.h"
#include <fstream>
#include <sstream>

void RatingManager::addRating(const Rating& rating) {
    ratings.push_back(rating);
}

std::vector<Rating> RatingManager::getRatingsByUser(int userId) const {

    std::vector<Rating> result;

    for (const auto& r : ratings) {
        if (r.getUserId() == userId)
            result.push_back(r);
    }

    return result;
}

const std::vector<Rating>& RatingManager::getAllRatings() const {
    return ratings;
}

void RatingManager::loadFromFile(const std::string& filename) {

    std::ifstream file(filename);

    int userId, movieId, score;
    char comma;

    while (file >> userId >> comma >> movieId >> comma >> score) {
        ratings.push_back(Rating(userId, movieId, score));
    }
}

void RatingManager::saveToFile(const std::string& filename) {

    std::ofstream file(filename);

    for (const auto& r : ratings) {
        file << r.getUserId() << ","
             << r.getMovieId() << ","
             << r.getScore() << "\n";
    }
}

int RatingManager::size() const {
    return ratings.size();
}
