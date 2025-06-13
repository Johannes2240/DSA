//Graph Type: Directed Graph (unweighted)


class Solution {
public:
    unordered_map<int, Employee*> employeeMap;

    int calculateImportance(int empId) {
        Employee* emp = employeeMap[empId];
        int totalImportance = emp->importance;
        for (int subId : emp->subordinates) {
            totalImportance += calculateImportance(subId);
        }
        return totalImportance;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (Employee* emp : employees) {
            employeeMap[emp->id] = emp;
        }
        return calculateImportance(id);
    }
};
