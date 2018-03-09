#ifndef _WINDOW_
#define _WINDOW_

// std
#include <list>
#include <QWidget>

// Qt
#include <QString>
#include "scene.h"
#include "ui_refinement.h"

class MainWindow : public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT

private:
	Scene* m_scene;

	unsigned int maxNumRecentFiles;
	QAction* recentFilesSeparator;
	QVector<QAction*> recentFileActs;

public:
	MainWindow();
	~MainWindow();

	void update();

protected:
	void addRecentFiles(QMenu* menu, QAction* insertBefore = 0);    
	unsigned int maxNumberOfRecentFiles() const {return maxNumRecentFiles;}

	protected slots:

		// drag & drop
		void dropEvent(QDropEvent *event);
		void closeEvent(QCloseEvent *event);
		void dragEnterEvent(QDragEnterEvent *event);

		// recent files
		void openRecentFile_aux();
		void updateRecentFileActions();
		void addToRecentFiles(QString fileName);

		// io
		void on_actionLoad_triggered();
		void open(const QString& file);

public slots:

	    // Data
			void on_actionBox_triggered();
			void on_actionCircle_triggered();
			void on_actionClear_triggered();

			// algorithms
			void on_actionRefine_triggered();
			void on_actionDelaunay_conforming_triggered();
			void on_actionGabriel_conforming_triggered();

signals:
			void openRecentFile(QString filename);
};

#endif // _WINDOW_
