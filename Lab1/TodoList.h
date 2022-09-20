#ifndef TODOLIST_H_
#define TODOLIST_H_

#include "TodoListInterface.h"
#include <string>

class TodoList : public TodoListInterface {
    private:
        //Data fields
        std::string _day, _task;

    public:
        //Contructors
        TodoList() {}
        ~TodoList() {}

        //Methods
        void add(std::string _duedate, std::string _task);
        int remove(std::string _task);
        void printTodoList();
        void printDaysTasks(std::string _date);
};

#endif