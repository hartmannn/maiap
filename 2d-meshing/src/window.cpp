// Qt
#include <QtGui>
#include <QActionGroup>
#include <QFileDialog>
#include <QInputDialog>
#include <QClipboard>

#include "window.h"

#include <fstream>

MainWindow::MainWindow() : 
QMainWindow(), Ui_MainWindow(), 
maxNumRecentFiles(15), recentFileActs(15)
{
	setupUi(this);
    
	// init scene
	m_scene = new Scene;
	viewer->set_scene(m_scene);
    
	// accepts drop events
	setAcceptDrops(true);
    
	// Handling actions
	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    
	addRecentFiles(menuFile, actionQuit);
	connect(this, SIGNAL(openRecentFile(QString)), this, SLOT(open(QString)));
}

MainWindow::~MainWindow()
{
	delete m_scene;
}

void MainWindow::update()
{
	viewer->repaint();
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
	Q_FOREACH(QUrl url, event->mimeData()->urls())
	{
		QString filename = url.toLocalFile();
		if (!filename.isEmpty())
		{
			QTextStream(stderr) << QString("dropEvent(\"%1\")\n").arg(filename);
			open(filename);
		}
	}
	event->acceptProposedAction();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	event->accept();
}

void MainWindow::addToRecentFiles(QString fileName)
{
    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > (int)maxNumRecentFiles)
        files.removeLast();
    settings.setValue("recentFileList", files);
    updateRecentFileActions();
}

void MainWindow::updateRecentFileActions()
{
    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();
    
    int numRecentFiles = qMin(files.size(), (int)maxNumberOfRecentFiles());
    for (int i = 0; i < numRecentFiles; ++i) {
        QString strippedName = QFileInfo(files[i]).fileName();
        QString text = tr("&%1 %2").arg(i).arg(strippedName);
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (unsigned int j = numRecentFiles; j < maxNumberOfRecentFiles(); ++j)
        recentFileActs[j]->setVisible(false);
    
    recentFilesSeparator->setVisible(numRecentFiles > 0);
}

void MainWindow::addRecentFiles(QMenu* menu, QAction* insertBeforeAction)
{
    if (insertBeforeAction)
        recentFilesSeparator = menu->insertSeparator(insertBeforeAction);
    else 
        recentFilesSeparator = menu->addSeparator();
    recentFilesSeparator->setVisible(false);
    
    for (unsigned int i = 0; i < maxNumberOfRecentFiles(); ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()), this, SLOT(openRecentFile_aux()));
        if (insertBeforeAction)
            menu->insertAction(insertBeforeAction, recentFileActs[i]);
        else
            menu->addAction(recentFileActs[i]);
    }
    updateRecentFileActions();
}

void MainWindow::openRecentFile_aux()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (action)
        emit openRecentFile(action->data().toString());
}

void MainWindow::open(const QString& filename)
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
	m_scene->load(filename);
	QApplication::restoreOverrideCursor();
	addToRecentFiles(filename);
	update();
}

void MainWindow::on_actionClear_triggered()
{
	m_scene->clear();
	update();
}

void MainWindow::on_actionLoad_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open PSLG"), ".");
	if (!fileName.isEmpty())
		open(fileName);
}

void MainWindow::on_actionBox_triggered()
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
  m_scene->add_box();
	QApplication::restoreOverrideCursor();
	update();
}

void MainWindow::on_actionCircle_triggered()
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
  m_scene->add_circle();
	QApplication::restoreOverrideCursor();
	update();
}



// refinement
void MainWindow::on_actionRefine_triggered()
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
  m_scene->refine();
	QApplication::restoreOverrideCursor();
	update();
}

// Delaunay conforming
void MainWindow::on_actionDelaunay_conforming_triggered()
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
  m_scene->delaunay_conforming();
	QApplication::restoreOverrideCursor();
	update();
}

// Gabriel conforming
void MainWindow::on_actionGabriel_conforming_triggered()
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
  m_scene->gabriel_conforming();
	QApplication::restoreOverrideCursor();
	update();
}


