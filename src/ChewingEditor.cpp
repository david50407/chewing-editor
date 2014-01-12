#include "ChewingEditor.h"
#include "ui_ChewingEditor.h"

#include <QtGui>

ChewingEditor::ChewingEditor(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::ChewingEditor),
    model_(UserphraseModelFactory())
{
    ui_.get()->setupUi(this);
    ui_.get()->userphraseView->setModel(model_.get());
}

ChewingEditor::~ChewingEditor()
{}
