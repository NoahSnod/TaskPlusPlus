#include "../headers/taskList.h"
#include "gtest/gtest.h"

TEST(TestingComplete, originallyCompleted) {
    TaskList newList;
    newList.switchCompleteStatus();

    EXPECT_TRUE(newList.getListCompleteStatus() == true);
}

TEST(TestingComplete, originallyUncompleted) {
    TaskList newList;

    EXPECT_TRUE(newList.getListCompleteStatus() == false);
}

TEST(TestingName, nameEmpty) {
    TaskList newList;

    EXPECT_TRUE(newList.getListName() == "");
}

TEST(TestingName, nameNotEmpty) {
    TaskList newList;
    newList.editListName("Test");

    EXPECT_TRUE(newList.getListName() == "Test");
}

TEST(TestingClassification, classificationWeekly) {
    TaskList newList;
    newList.editListClassification("Weekly");

    EXPECT_TRUE(newList.getListClassification() == "Weekly");
}

TEST(TestingTaskListClassification, classificationChange) {
    TaskList newList;
    newList.editListClassification("Weekly");
    newList.editListClassification("Upcoming");

    EXPECT_TRUE(newList.getListClassification() == "Upcoming");
}

TEST(TestingDescription, descriptionEmpty) {
    TaskList newList;

    EXPECT_TRUE(newList.getListDescription() == "");
}

TEST(TestingDescription, descriptionNotEmpty) {
    TaskList newList;
    newList.editListDescription("Testing 1 2 3");

    EXPECT_TRUE(newList.getListDescription() == "Testing 1 2 3");
}

TEST(TestingAdd, oneTask) {
    TaskList newList;
    Task *t1 = new Task;
    newList.addTask(t1);

    EXPECT_TRUE(newList.getNumOfTasks() == 1);
}

TEST(TestingAdd, multipleTask) {
    TaskList newList;
    Task *t1 = new Task;
    Task *t2 = new Task;
    Task *t3 = new Task;
    Task *t4 = new Task;

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_TRUE(newList.getNumOfTasks() == 4);
}

TEST(TestingProgression, noneCompleted) {
    TaskList newList;
    Task *t1, *t2, *t3, *t4;
    t1 = new Task;
    t2 = new Task;
    t3 = new Task;
    t4 = new Task;

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_DOUBLE_EQ(newList.getProgress(), 0);
}

TEST(TestingProgression, someCompleted) {
    TaskList newList;
    Task *t1, *t2, *t3, *t4;
    t1 = new Task;
    t2 = new Task;
    t3 = new Task;
    t4 = new Task;

    t1->switchCompleteStatus();

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_DOUBLE_EQ(newList.getProgress(), 25.0);
}

TEST(TestingProgression, allCompleted) {
    TaskList newList;
    Task *t1, *t2, *t3, *t4;
    t1 = new Task;
    t2 = new Task;
    t3 = new Task;
    t4 = new Task;

    t1->switchCompleteStatus();
    t2->switchCompleteStatus();
    t3->switchCompleteStatus();
    t4->switchCompleteStatus();

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_DOUBLE_EQ(newList.getProgress(), 100.0);
}

TEST(TestingEditTask, stringNewVal) {
    TaskList *newList = new TaskList;
    Task *t1 = new Task;
    newList->addTask(t1);

    string priority = "High";
    string description = "NEED TO DO ASAP";

    t1->setName("Test Task");
    t1->setPriority(priority);
    t1->setDescription(description);

    newList->editTask("Test Task", "Priority", priority);
    newList->editTask("Test Task", "Description", description);

    EXPECT_TRUE(t1->getPriority() == priority);
    EXPECT_TRUE(t1->getDescription() == description);

    delete newList;
}

TEST(TestingRemove, oneTask) {
    TaskList newList;
    Task *t1 = new Task;
    newList.addTask(t1);

    string name = "Test";
    t1->setName(name);

    newList.removeTask(name);
    EXPECT_EQ(newList.getNumOfTasks(), 0);
}

TEST(TestingRemove, multipleTask) {
    TaskList newList;
    Task *t1 = new Task;
    Task *t2 = new Task;
    Task *t3 = new Task;

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);

    string name1 = "Test";
    string name2 = "Test2";
    string name3 = "Test3";

    t1->setName(name1);
    t2->setName(name2);
    t3->setName(name3);

    EXPECT_EQ(newList.getNumOfTasks(), 3);
    newList.removeTask(name1);
    newList.removeTask(name2);
    newList.removeTask(name3);
    EXPECT_EQ(newList.getNumOfTasks(), 0);
}

TEST(TestingRemove, taskUnexistant) {
    TaskList newList;
    Task *t1 = new Task;
    newList.addTask(t1);

    string name = "Test";

    newList.removeTask(name);
    EXPECT_EQ(newList.getNumOfTasks(), 1);
}