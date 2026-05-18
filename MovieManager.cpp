#include "MovieManager.h"
#include <fstream>
#include <sstream>

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

const std::vector<Movie>& MovieManager::getMovies() const {
    return movies;
}

Movie* MovieManager::findMovieById(int id) {

    for (auto& movie : movies) {
        if (movie.getId() == id)
            return &movie;
    }

    return nullptr;
}

void MovieManager::loadFromFile(const std::string& filename) {

    std::ifstream file(filename);

    int id, year;
    std::string title, genre;

    while (file >> id >> title >> genre >> year) {

        movies.push_back(
            Movie(id, title, genre, year)
        );
    }
}

void MovieManager::saveToFile(const std::string& filename) {

    std::ofstream file(filename);

    for (const auto& movie : movies) {

        file << movie.getId() << " "
             << movie.getTitle() << " "
             << movie.getGenre() << " "
             << movie.getReleaseYear()
             << "\n";
    }
}

int MovieManager::size() const {
    return movies.size();
}
