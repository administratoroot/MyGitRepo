#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GSPGridDataSource.h"
#include "GSPGridDataSourceModel.h"
#include "GSPComboBox.h"
#include "mydelegate.h"
#include "myfunction.h"
#include "testafterinsertrecord.h"
#include "testparseconstevent.h"

namespace Ui {
class MainWindow;
}
class MyDelegate;
class TestEventHandle;
class TestAfterInsertRecord;
class TestParseConstEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void loadData();
    void loadUI();
    void loadMenu();
    void buildGridSetting();
private slots:
    void testFunction();
    void doDebug();

private:
    Ui::MainWindow *ui;
    GSPTableView *m_tableView;
    GSPGridDataSource *m_dataSource;
    GSPGridDataSourceModel *m_dataSourceModel;
    GSPModel m_model;
    MyDelegate *m_delegate;
    TestEventHandle *m_eventHandle;
    TestAfterInsertRecord *m_afterInsertRecord;
    GSPComboBox *m_comboBox;
};





#endif // MAINWINDOW_H
