#pragma once
#include <vector>
#include "Rating.h"
#include "BaseManager.h"

class RatingManager : public BaseManager {
private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& rating);

    std::vector<Rating> getRatingsByUser(int userId) const;

    const std::vector<Rating>& getAllRatings() const;

    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) override;
    int size() const override;
};
