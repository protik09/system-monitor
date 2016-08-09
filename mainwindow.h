#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QThread>
#include "processinformationworker.h"
#include <proc/readproc.h>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleTabChange();
    void updateProcessInformation();

private:
    QTabWidget* mainTabs;
    QTableWidget* processesTable;
    void createProcessesView();
    processInformationWorker* processesThread;
    bool processesThreadStarted;
    void stopRunningProcessesThread();
};

#endif // MAINWINDOW_H
