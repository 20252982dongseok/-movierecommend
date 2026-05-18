#include <iostream>
#include "RatingManager.h"
#include "Recommender.h"

int main() {

    RatingManager rm;

    rm.addRating(Rating(1, 101, 5));
    rm.addRating(Rating(1, 102, 4));

    rm.addRating(Rating(2, 101, 5));
    rm.addRating(Rating(2, 103, 5));

    rm.addRating(Rating(3, 102, 4));
    rm.addRating(Rating(3, 104, 5));

    Recommender recommender(rm);

    auto result = recommender.recommend(1, 3);

    std::cout << "추천 영화:\n";

    for (int movieId : result) {
        std::cout << movieId << std::endl;
    }

    return 0;
}
