#include <iostream>
using namespace std;

#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

#include "algorithms.h"
#include "Graph.h"


int main(){
    ifstream cities_file("EuropeCities.csv");
    ofstream sorted_cites_file("output603-1.out");
    ofstream adjacency_list_file_train("output603-2-train.out");
    ofstream adjacency_list_file_car("output603-2-car.out");
    ofstream bfs_file("output603-3.out");
    ofstream dfs_file("output603-4.out");
    string line;
    set<string> unique_cities;
    Graph<string> train_graph;
    Graph<string> car_graph;
    

    //used to remove the first line
    getline(cities_file, line);

    while(getline(cities_file, line)){
        stringstream ss(line);
        string city;
        string city2;
        string trainTime;
        string trainDist;
        string carTime;
        string carDist;

        getline(ss, city, ',');
        getline(ss, city2, ',');
        getline(ss, trainTime, ',');
        getline(ss, trainDist, ',');
        getline(ss, carTime, ',');
        getline(ss, carDist, ',');

        train_graph.addVertex(city);
        train_graph.addVertex(city2);
        car_graph.addVertex(city);
        car_graph.addVertex(city2);

        Edge<string> edge_train(city, city2, stoi(trainDist), trainTime);
        train_graph.addEdge(edge_train);
        Edge<string> edge_car(city, city2, stoi(carDist), carTime);
        car_graph.addEdge(edge_car);

        
        unique_cities.insert(city);

    }

    

    return 0;
}