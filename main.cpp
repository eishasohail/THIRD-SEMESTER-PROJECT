#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class MovieRecommender {
    map<string, list<string>> graph; // Graph for connections
    map<string, vector<string>> movieData; // Movie attributes (content)
public:
    // Load graph data
    void loadGraph(const string& filename) {
        ifstream file(filename);
        if(!file) {
            cout<<"Error: Cannot open graph file!"<<endl;
            return;
        }
        string movie1, movie2;
        while(file>>movie1>>movie2) {
            graph[movie1].push_back(movie2);
            graph[movie2].push_back(movie1); // Bidirectional edge
        }
        file.close();
        cout<<"Graph loaded successfully!"<<endl;
    }
    // Load movie attributes (content)
    void loadMovieData(const string& filename) {
        ifstream file(filename);
        if(!file) {
            cout<<"Error: Cannot open movie data file!"<<endl;
            return;
        }
        string movie, genre, director, year;
        while(file>>movie>>genre>>director>>year) {
            movieData[movie] = {genre, director, year};
        }
        file.close();
        cout<<"Movie data loaded successfully!"<<endl;
    }
    // Recommend movies (Hybrid approach)
    void recommendMovies(const string& movie) {
        if(graph.find(movie) == graph.end()) {
            cout<<"Movie not found in the graph!"<<endl;
            return;
        }
        cout<<"Finding recommendations for "<<movie<<"...\n";
        // Step 1: Use BFS to find graph-based candidates
        set<string> visited;
        queue<string> q;
        vector<string> candidates;
        q.push(movie);
        visited.insert(movie);
        while(!q.empty()) {
            string current = q.front();
            q.pop();
            for(const auto& neighbor : graph[current]) {
                if(visited.find(neighbor) == visited.end()) {
                    candidates.push_back(neighbor);
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        // Step 2: Rank candidates using content-based similarity
        vector<pair<string, double>> recommendations;
        for(const auto& candidate : candidates) {
            if(movieData.find(candidate) != movieData.end() && movieData.find(movie) != movieData.end()) {
                double similarity = calculateSimilarity(movieData[movie], movieData[candidate]);
                recommendations.push_back({candidate, similarity});
            }
        }
        // Sort recommendations by similarity (highest first)
        sort(recommendations.begin(), recommendations.end(),
             [](const pair<string, double>& a, const pair<string, double>& b) {
                 return a.second > b.second;
             });
        // Step 3: Display top recommendations
        cout<<"Recommendations for "<<movie<<":\n";
        for(int i = 0; i < min(3, (int)recommendations.size()); i++) {
            cout<<"- "<<recommendations[i].first<<" (Similarity: "<<recommendations[i].second * 100<<"%)\n";
        }
    }
private:
    // Calculate similarity based on matching attributes
    double calculateSimilarity(const vector<string>& movie1, const vector<string>& movie2) {
        int matchCount = 0;
        for(size_t i = 0; i < movie1.size(); i++) {
            if(movie1[i] == movie2[i]) {
                matchCount++;
            }
        }
        return (double)matchCount / (double)movie1.size(); // Normalize by total attributes
    }
};
int main() {
    MovieRecommender recommender;
    // Load data
    recommender.loadGraph("graph.txt");
    recommender.loadMovieData("movies.txt");
    // Ask user for input
    string movie;
    cout<<"Enter a movie name for recommendations: ";
    cin>>movie;
    // Provide recommendations
    recommender.recommendMovies(movie);
    return 0;
}
