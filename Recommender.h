#pragma once
#include <vector>
#include "RatingManager.h"

class Recommender {
private:
    RatingManager& ratingManager;

public:
    Recommender(RatingManager& rm);

    std::vector<int> recommend(int targetUserId, int topN);
};
