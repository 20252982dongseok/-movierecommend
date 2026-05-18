#include "Rating.h"

Rating::Rating(int userId, int movieId, int score)
    : userId(userId), movieId(movieId), score(score) {}

int Rating::getUserId() const {
    return userId;
}

int Rating::getMovieId() const {
    return movieId;
}

int Rating::getScore() const {
    return score;
}
