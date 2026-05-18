#pragma once
#include <vector>
#include "Movie.h"
#include "BaseManager.h"

class MovieManager : public BaseManager {
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie& movie);

    const std::vector<Movie>& getMovies() const;

    Movie* findMovieById(int id);

    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) override;
    int size() const override;
};
