#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "GSPEngineUtils.h"
#include "GLDFileUtils.h"
#include "GSPActions.h"
#include "GLDTableViewExport.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadUI();
    loadData();
    loadMenu();
}

//执行detach事件
MainWindow::~MainWindow()
{
    m_dataSource->queryCellValueEventList().remove(m_eventHandle);
    m_dataSource->queryCellAttributeEventList().remove(m_eventHandle);
    freeAndNil(m_eventHandle);

    if (m_model[0].findTable("KH").tableSchema().recordEventContainer().afterInsertEventList().exist(m_afterInsertRecord))
    {
        m_model[0].findTable("KH").tableSchema().recordEventContainer().afterInsertEventList().detach(m_afterInsertRecord);
    }
    freeAndNil(m_afterInsertRecord);
    freeAndNil(m_delegate);
    delete ui;
}

//加载数据并绑定界面
void MainWindow::loadData()
{
    m_model = gspEngine().createModel();
    GSPModelPersistent(m_model).loadFromFile(exePath() + "Northwind.GSP", false, false);

    //GSPModel iModelOld = gspEngine().createModel();
    //GSPModelPersistent(iModelOld).loadFromFile(exePath() + "aa.GSP", false, false);
    //GSPModel iModel = iModelOld.clone(false, true);

    GSPViews iViews;
    iViews.push_back(m_model[0].findTable("KH").createView("", NULL));
    //iViews.push_back(m_model[0].findTable("DD").createView("", NULL));
    m_dataSource = new GSPGridDataSource();
    m_dataSource->setViews(iViews);

    m_dataSourceModel = new GSPGridDataSourceModel(this);
    m_dataSourceModel->setDataSource(m_dataSource);
    m_dataSourceModel->setGridSettingFileName(exePath() + "KH.GSF");
    buildGridSetting();
    m_dataSourceModel->setActive(true);

    m_tableView->setModel(m_dataSourceModel);

    m_delegate = new MyDelegate();
    m_delegate->setDataSourceModel(m_dataSourceModel);
    m_tableView->setItemDelegate(m_delegate);

    //m_comboBox->setDataSource(m_dataSource);
    //m_comboBox->setFieldName("home");

    m_eventHandle = new TestEventHandle();
    m_dataSource->queryCellValueEventList().push_back(m_eventHandle);
    m_dataSource->queryCellAttributeEventList().push_back(m_eventHandle);

    GSPTable iTable = m_model[0].findTable("KH");
    m_afterInsertRecord = new TestAfterInsertRecord();
    if (! iTable.tableSchema().recordEventContainer().afterInsertEventList().exist(m_afterInsertRecord))
    {
        iTable.tableSchema().recordEventContainer().afterInsertEventList().attach(m_afterInsertRecord, "", false);
    }
	
}


void MainWindow::loadUI()
{
    m_tableView = new GSPTableView(ui->centralWidget);
    m_tableView->setGeometry(0, 0, 600, 300);

	//m_comboBox = new GSPComboBox(ui->centralWidget);
	//m_comboBox->setGeometry(600, 0, 50, 50);
}

void MainWindow::loadMenu()
{
    GSPInsertAction *acInsert = new GSPInsertAction("Insert", this);
    acInsert->setDataSource(m_dataSource);
    acInsert->setBefore(false);
    acInsert->setKind(gikAppend);
    acInsert->setViewIndex(0);
    ui->mainToolBar->addAction(acInsert);

    GSPDeleteAction *acDeleteAction = new GSPDeleteAction("Del", this);
    acDeleteAction->setDataSource(m_dataSource);
    acDeleteAction->setIsTree(true);
    ui->mainToolBar->addAction(acDeleteAction);

   /* QAction *acFunction = new QAction("TestFun", this);
    connect(acFunction, SIGNAL(triggered()), this, SLOT(testFunction()));
    ui->mainToolBar->addAction(acFunction);

    QAction *acDebug = new QAction("Debug", this);
    connect(acDebug, SIGNAL(triggered()), this, SLOT(doDebug()));
    ui->mainToolBar->addAction(acDebug);*/
}

//动态修改GSF
void MainWindow::buildGridSetting()
{
    GSPGridSetting *oGridSetting = m_dataSourceModel->gridDataSource()->gridSetting();
    oGridSetting->setDesignState(true);
    try
    {
        //GSPColSetting *oColSetting = dynamic_cast<GSPColSetting *>(oGridSetting->colSettings()->insert());
        //int nIndex = oGridSetting->colSettings()->indexOf(oColSetting);
        //oColSetting->setDisplayWidth(80);
        //oGridSetting->titleRows()->items(0)->cells(nIndex)->setCaption("dz");
        //oGridSetting->tableSettings()->items(0)->fieldSettings()->items(nIndex)->setEditFieldName("dz");
    }
    catch (...)
    {
        oGridSetting->setDesignState(false);
        throw;
    }
    oGridSetting->setDesignState(false);
}

//自定义函数执行
void MainWindow::testFunction()
{
    MyFunction *oFun = new MyFunction();
    m_model.gepEngine().functionCenter().Register((IGEPFunction *)oFun);

    GEPParser iParser = m_model.gepEngine().createParser();
    iParser.setExpression("aaa()");
    iParser.evaluate();
//    GString strValue = iParser.result().asString();
    int nValue = iParser.result().asInteger();

    TestParseConstEvent *oEvent = new TestParseConstEvent();
    iParser = m_model.gepEngine().createParser();
    iParser.setExpression("aaa(1+2)", NULL, oEvent);
    iParser.evaluate();
    nValue = iParser.result().asInteger();
//    QMessageBox::information(NULL, "Result", strValue, QMessageBox::Ok);
}

//插入一条数据
void MainWindow::doDebug()
{
    GSPTable iTable = m_model[0].findTable("KH");
    GSPRecord iRecord = iTable.newRecord();
    iTable.append(iRecord);
}

//设置编辑方式
GEditStyle MyDelegate::editStyle(GSPCustomRowNode *rowNode, int dataCol, bool &readOnly) const
{
    if (3 == dataCol)
    {
        return esDropDown;
    }
    else
    {
        return GSPDefaultItemDelegate::editStyle(rowNode, dataCol, readOnly);
    }
}

//queryCell改变值
void TestEventHandle::onQueryCellValue(GSPCustomRowNode *rowNode, int col, GSPField field, GSPRecord record, GVariant &value, bool &handled)
{
    G_UNUSED(handled);
    G_UNUSED(record);
    G_UNUSED(field);
//    if ((4 == col) && (2 == rowNode->rowNo()))
//    {
//        QImage oImage = QImage(":/res/res/Add16.png");
//        oImage.setText("Image", "..\\bin\\Add16.png");
//        value = oImage;
//    }
//    else if ((4 == col) && (1 == rowNode->rowNo()))
//    {
//        QImage oImage = QImage(":/res/res/back.png");
//        oImage.setText("Image", "..\\bin\\back.png");
//        value = oImage;
//    }
}

//设置queryCellAttribute
void TestEventHandle::onQueryCellAttribute(GSPCustomRowNode *rowNode, int col, GSPField field, GSPRecord record, int role, GVariant &attribute, bool &handled)
{
    G_UNUSED(handled);
    G_UNUSED(rowNode);
    if (3 == col)
    {
        if (role == Qt::BackgroundColorRole)
        {
            attribute = QColor(0xFF, 0xFF, 0xC8);
        }
    }
    else if (4 == col)
    {
        if (Qt::TextAlignmentRole == role)
        {
            attribute = Qt::AlignHCenter;
        }
    }
}

//插入后触发引擎的事件
void TestAfterInsertRecord::afterInsertRecord(GSPRecord &record)
{
    G_UNUSED(record);
    //QMessageBox::information(NULL, "Test", "Insert Ok", QMessageBox::Ok);
}

GString MyFunction::name()
{
    return "aaa";
}

GEPDataType MyFunction::resultDataType()
{
    return edtInteger;
}

GEPDataMatchType MyFunction::matchParam(long paramCount, IGEPNodeList *params)
{
    G_UNUSED(paramCount);
    G_UNUSED(params);
    return dmtExact;
}

void MyFunction::execute(long paramCount, IGEPNodeList *params, IGEPData *result)
{
    G_UNUSED(paramCount);
    G_UNUSED(params);
    int value = result->asInteger();
    result->setAsInteger(value + 1);
}



void TestParseConstEvent::onQueryConstValue(const GString &constCode, GString &value, void *info)
{
    int k = 1;
    k++;
}
