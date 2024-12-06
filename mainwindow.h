#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <truck_show_display.h>
#include <moto_show_display.h>
#include <p_car_show_display.h>
#include <mark_manager.h>
#include <QComboBox>
#include <mark_container_manager.h>
#include <model_container_manager.h>
#include <QLineEdit>
#include <QValidator>
#include <QMap>
#include <QVBoxLayout>
#include "paginator.h"
#include <transport_loader.h>
#include<combo_box_controller.h>
#include<undo_redo_manager.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void onComboBoxMarkToEdit(int index);

    void onComboBoxTypeToEditModel(int index);

    void onComboBoxModelToEditChanged(int index);

    void onModelAddBoxChanged(int id);

    void onAddMarkFieldChanged();

    void on_showButton_clicked();

    void on_addObjectConfirmed_clicked();

    void on_showAddGroupBox_clicked();

    void on_returnToMainPage_clicked();

    void on_selectImageButton_clicked();

    void on_cancelImageButton_clicked();

    void on_addMarkButton_clicked();

    void on_returnToAddPage_clicked();

    void on_addNewModelButton_clicked();

    void onTransportButtonClicked();

    void updateGrid(const vector<int> &pageIds);

    void updatePaginationControls(int currentPage, int totalPages);

    void clearPageContent();

    void on_closeInfoButton_clicked();

    void on_deleteButton_clicked();

    void on_delMarkAndModelButton_clicked();

    void on_returnToMainPageFromDel_clicked();

    void onComboBoxMarkToEditModel(int index);

    void on_editMarkButton_a_clicked();

    void on_editMarkButton_clicked();

    void on_deleteMarkButton_clicked();

    void on_editModelButton_clicked();

    void on_deleteModelButton_clicked();

    void on_editModelButton_a_clicked();

    void on_editButton_clicked();

    void on_acceptChanges_clicked();

    void on_redoButton_clicked();

    void on_undoButton_clicked();

private:
    Ui::MainWindow *ui;

    UndoRedoManager *undoRedoManager;

    ComboBoxController *comboBoxController;

    MarkContainerManager markContainerManager;

    ModelContainerManager modelContainerManager;

    MarkManager markManager;

    ModelManager modelManager;

    MotoShowDisplay _motoSD;

    PasCarShowDisplay _pasCarSD;

    TruckShowDisplay  _truckSD;

    QMap<QString, QLineEdit*> inputFields;

    Paginator *paginator;

    void updateButtonStates();

    void loadMarks();

    void clearMarks();

    void clearModels();

    void setupInputFields(const QString &type, QGroupBox *box);

    bool validateFields();

    void clearInputFields();

    void loadModels(int markId, const string &type, QComboBox *box);

    void loadTransportDataById(int id, QPushButton *button, const string& type);

};
#endif // MAINWINDOW_H
