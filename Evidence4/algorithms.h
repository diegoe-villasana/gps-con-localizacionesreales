template <class T>
void swap(vector<T> &list, int a, int b)
{
    // validamos que sean diferentes
    if (a!=b)
    {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template <class T>
int getPivot(vector<T> &list, int left, int right){
    int aux = left-1;
    int pivot = right;
    for(int i=left; i<right; i++){
        if(list[i]<list[pivot]){
            aux++;
            swap(list, i, aux);
        }
    }
    aux++;
    swap(list, pivot, aux);
    return aux;
}

template <class T>
void quickSort(vector<T> &list, int left, int right){
    if(left<right){
        int pivot = getPivot(list, left, right);
        quickSort(list, left, pivot-1);
        quickSort(list, pivot+1, right);
    }   
}

