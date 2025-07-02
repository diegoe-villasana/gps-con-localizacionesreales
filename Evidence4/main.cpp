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
    
    vector<string> menu{
        "sort_cities",
        "adjacency_lists",
        "traversal",
        "dijkstra",
        "exit"
    };
    int option = 0;
    string operation = "";

    while(operation!="exit"){
        cout << "Select an option:" << endl;
        for(int i = 0; i < menu.size(); i++){
            cout << i+1 << ". " << menu[i] << endl;
        }
        cin >> option;
        operation = menu[(option-1)%menu.size()];

        if(operation == "sort_cities"){
            vector<string> unique_cities_vector(unique_cities.begin(), unique_cities.end());
            quickSort(unique_cities_vector, 0, unique_cities_vector.size()-1);
            sorted_cites_file << "Sorted cities:" << endl;
            for(int i = 0; i < unique_cities_vector.size(); i++){
                sorted_cites_file << unique_cities_vector[i] << endl;
            }
        }else if(operation == "adjacency_lists"){
            //ajacency list for train in output603-2-train.out
            adjacency_list_file_train << "Adjacency list for train:" << endl;
            for (int i=0; i<train_graph.vertices.size(); i++) {
                adjacency_list_file_train << train_graph.vertices[i] << " - ";
                for (auto edge : train_graph.adjacencyList[i]) {
                    adjacency_list_file_train << edge.target << " " << edge.weight << " - " << edge.time << " | ";
                }
                adjacency_list_file_train << endl;
            }
            //ajacency list for car in output603-2-car.out
            adjacency_list_file_car << "Adjacency list for car:" << endl;
            for (int i=0; i<car_graph.vertices.size(); i++) {
                adjacency_list_file_car << car_graph.vertices[i] << " - ";
                for (auto edge : car_graph.adjacencyList[i]) {
                    adjacency_list_file_car << edge.target << " " << edge.weight << " - " << edge.time << " | ";
                }
                adjacency_list_file_car << endl;
            }

        }else if(operation == "traversal"){
            string start_city;
            cout << "Enter a city to start the traversal: ";
            cin >> start_city;
            try{
                train_graph.bfs(start_city);
                //print elements of bfs_result_vector
                bfs_file << "BFS traversal starting from " << start_city << ":" << endl;
                for(int i = 0; i < train_graph.bfs_result_vector.size(); i++){
                    bfs_file << train_graph.bfs_result_vector[i] << endl;
                }    
            }catch(exception& e){
                cout << e.what() << endl;
            }

            try{
                train_graph.dfs(start_city);
                //print elements of dfs_result_vector
                dfs_file << "DFS traversal starting from " << start_city << ":" << endl;
                for(int i = 0; i < train_graph.dfs_result_vector.size(); i++){
                    dfs_file << train_graph.dfs_result_vector[i] << endl;
                }
            }catch(exception& e){
                cout << e.what() << endl;
            }

            
        }else if(operation == "dijkstra"){
            string start_city;
            string end_city;
            cout << "Enter a city to start the traversal: ";
            cin >> start_city;
            cout << "Enter a city to end the traversal: ";
            cin >> end_city;
            cout << "Tren - ";
            try{
                train_graph.dijkstra(start_city, end_city);
            }catch(exception& e){
                cout << e.what() << endl;
            }
            cout << "Carro - ";
            try{
                car_graph.dijkstra(start_city, end_city);
            }catch(exception& e){
                cout << e.what() << endl;
            }

        }

    }


    return 0;
}