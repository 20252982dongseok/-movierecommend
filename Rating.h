#pragma once
#include <iostream>

class Rating {
private:
    int userId;
    int movieId;
    int score;

public:
    Rating(int userId, int movieId, int score);

    int getUserId() const;
    int getMovieId() const;
    int getScore() const;
};
