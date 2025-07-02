#ifndef HashStudentId_h
#define HashStudentId_h

class HashStudentId {
private:
    vector<string> table;
    int hash(string studentId);
    vector<bool> status;
public:
    HashStudentId();
    // HashStudentId(int (*hash) (string));
    void insert(string studentId);
    void remove(string strudentId);
    int findStudentId(string studentId);
    void print();

};

HashStudentId::HashStudentId() {
    table.resize(50);
    status.resize(50, false);
}

int HashStudentId::hash(string studentId) {
    return stoi(studentId) % 38;
}

int HashStudentId::findStudentId(string studentId) {
    studentId = studentId.substr(1);
    int index = hash(studentId);
    if (table[index] == studentId) {
        return index;
    } else {
        int newIndex = (index + 1) % table.size();
        // Recorremos la tabla para buscar el elemento
        while (index != newIndex && (!table[index].empty() || status[index])) {
            // Validamos si el valor de la tabla en newIndex es igual al valor buscado
            if (table[newIndex] == studentId) {
                // Regresamos newIndex
                return newIndex;
            }
            // Incrementamos el valor de newIndex
            newIndex = (newIndex + 1) % table.size();
        }
        // No lo encontré
        return -1;
    }
}

void HashStudentId::insert(string studentId) {
    studentId = studentId.substr(1);
    // Validar si existe el elemento
    if (findStudentId(studentId) == -1) {
        int index = hash(studentId);

        if (table[index].empty()) {
            // insertamos el dato
            table[index] = studentId;
            // Actualizamos el estado de newIndex
            status[index] = false;
        } else {
            int newIndex = (index + 1) % table.size();

            while (newIndex != index && !table[newIndex].empty()) {
                // Recorremos newIndex
                newIndex = (newIndex + 1) % table.size();
            }
            // Validamos que no le hayamos dado la vuelta a la tabla
            if (newIndex != index) {
                // insertamos el dato
                table[newIndex] = studentId;
                // Actualizamos el estado de newIndex
                status[newIndex] = false;
            } else {
                // Le dimos la vuelta a la tabla, es decir la tabla esta llena
                throw invalid_argument("La tabla esta llena");
            }
        }
    } else {
        throw invalid_argument("El valor ya se encuentra en la tabla");
    }     
}

void HashStudentId::remove(string studentId) {
    studentId = studentId.substr(1);
    int index = findStudentId(studentId);
    // Validamos si lo encontramos
    if (index != -1) {
        // Lo removemos
        table[index] = "";
        // Actualizamos la tabla de estados
        status[index] = true;
    } else {
        throw invalid_argument("El valor no se encuentra en la tabla");
    }
}

void HashStudentId::print() {
    for (int i=0; i<table.size(); i++) {
        cout << i << "-A" << table[i] << " ";
    }
    cout << endl;
}





#endif /* HashStudentId_h */
