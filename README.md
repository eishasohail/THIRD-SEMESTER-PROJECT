# THIRD-SEMESTER-PROJECT
🎬 Movie Recommendation System (C++)

This is a C++ project that implements a simple hybrid Movie Recommender System. The system suggests similar movies using a combination of graph-based connections and content-based filtering. It’s designed to work with two input text files: one containing connections between movies and the other containing content information such as genre, director, and release year.


---

📌 Description

The recommender works in two main phases:

Graph-Based Recommendation: It uses Breadth-First Search (BFS) to explore all movies that are directly or indirectly connected to the given movie. This models relationships between movies like sequels, shared universe, or viewer patterns.

Content-Based Filtering: Once candidate movies are identified via BFS, the program compares each one with the input movie using content features (genre, director, and release year). A similarity score is calculated based on the number of matching attributes.

Top Suggestions: The system then displays the top 3 most similar connected movies based on the content similarity score.



---

🧾 Files Included
Main.cpp – The main source code containing the class definition and recommendation logic.

graph.txt – Text file representing a graph of connected movies (each line contains two movie names).

movies.txt – Text file with movie attributes: movie name, genre, director, and year.

README.md – Documentation file with all necessary instructions and explanation (this file).



---

📂 File Formats

graph.txt should include pairs of movie names per line to define edges in the graph. Each pair represents a bidirectional connection.
Example:

Inception Interstellar
Inception Tenet
Interstellar Gravity

movies.txt should include four space-separated attributes: movie name, genre, director, and year.
Example:

Inception SciFi Nolan 2010  
Interstellar SciFi Nolan 2014  
Tenet SciFi Nolan 2020  
Gravity SciFi Cuaron 2013


⚠ Make sure movie names do not contain spaces unless you modify the code to use getline() instead of cin.


---

🖥 How to Compile and Run

To run this project, follow these steps:

Open a terminal in the folder containing your .cpp file and data files.

Compile the program using the following command:

g++ MovieRecommender.cpp -o recommender

Run the compiled program:

./recommender     # for Linux/macOS
recommender.exe   # for Windows

When prompted, enter the name of a movie to get recommendations.
Example:

Enter a movie name for recommendations: Inception



---

🧠 How Similarity is Calculated

The content similarity is computed by checking how many attributes match between the input movie and each connected movie. The attributes compared are:

Genre

Director

Year


For each match, one point is added. The similarity score is calculated as:

similarity = (number of matches) / (total attributes)

This means a movie with all 3 attributes matching will have 100% similarity.


---

📤 Sample Output

Enter a movie name for recommendations: Inception
Finding recommendations for Inception...
Recommendations for Inception:
- Tenet (Similarity: 100%)
- Interstellar (Similarity: 66.6667%)


---

🚀 Features

Combines collaborative filtering (graph-based) and content-based filtering.

Recommends top 3 similar movies.

Uses BFS for graph traversal.

Calculates content similarity based on shared genre, director, and year.

Easy to use with plain text files.



---

🔧 Possible Future Improvements

Add support for movie names with spaces using getline(cin, movie).

Include additional attributes like actors, ratings, or keywords.

Export recommendations to a separate output file.

Implement a simple graphical interface or web version.

Include user preferences or feedback for personalized results.

👥 Team Members

This project is developed as a collaborative semester project by the following team members from NED UNIVERSITY.Each member is showcasing the project individually on their Github profile:

EISHA SOHAIL
MENAHIL ALI
MARYAM RIZWAN
IFRA RIZWAN

📌 Note: This is a shared group project. All members contributed and may upload identical code to their personal repositories for portfolio purposes.
