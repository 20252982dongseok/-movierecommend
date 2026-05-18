CXX=g++
CXXFLAGS=-std=c++17

OBJS=main.o Rating.o User.o Movie.o \
RatingManager.o SimilarityCalculator.o \
Recommender.o

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

clean:
	rm -f *.o main
