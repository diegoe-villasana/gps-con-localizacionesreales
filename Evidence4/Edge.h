#pragma once

template <class T>
struct Edge {
    T source;
    T target;
    int weight;
    string time;
    Edge();
    Edge(T source, T target);
    Edge(T source, T target, int weight);
    Edge(T source, T target, int weight, string time);
};

template <class T>
Edge<T>::Edge() {
    weight = 0;
}

template <class T>
Edge<T>::Edge(T source, T target) {
    this->source = source;
    this->target = target;
    this->weight = 0;
}

template <class T>
Edge<T>::Edge(T source, T target, int weight) {
    this->source = source;
    this->target = target;
    this->weight = weight;
}

template <class T>
Edge<T>::Edge(T source, T target, int weight, string time) {
    this->source = source;
    this->target = target;
    this->weight = weight;
    this->time = time;
}