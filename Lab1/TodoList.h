#ifndef TODOLIST_H_
#define TODOLIST_H_

#include "TodoListInterface.h"
#include <string>

class TodoList : public TodoListInterface {
    private:
        ////Data fields
        std::string _day;
        std::string _task;

    public:
        //Methods
        TodoList(std::string day, std::string task);
        void add(std::string _duedate, std::string _task);
        int remove(std::string _task);
        void printTodoList();
        void printDaysTasks(std::string _date);
};

#endif