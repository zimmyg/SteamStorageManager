#include "ssm.h"
#include "qdebug.h"
#include "qdir.h"

ssm::ssm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	fastViewModel = new QStringListModel( this );
	massViewModel = new QStringListModel( this );

	QDir fastDir = QDir("C:\\Program Files (x86)\\Steam\\steamapps\\common");
	QDir massDir = QDir("D:\\Steam Storage");

	// Symlink stuff doesn't work on Windows. Thanks for the heads up documentation!! /s
	fastDir.setFilter( QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot );
	massDir.setFilter( QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot );

	QStringList fastList = QStringList();
	QStringList massList = QStringList();

	for each ( QFileInfo fInfo in fastDir.entryInfoList() )
	{
		if( fInfo.canonicalFilePath().compare(fInfo.absoluteFilePath()) == 0 )
		{
			fastList.append( fInfo.fileName() );
		}
	}
	fastViewModel->sort( 0 );

	for each ( QFileInfo fInfo in massDir.entryInfoList() )
	{
		if( fInfo.canonicalFilePath().compare( fInfo.absoluteFilePath() ) == 0 )
		{
			massList.append( fInfo.fileName() );
		}
	}
	massViewModel->sort( 0 );

	fastViewModel->setStringList( fastList );
	massViewModel->setStringList( massList );

	ui.fastStorageView->setModel( fastViewModel );
	ui.massStorageView->setModel( massViewModel );

	ui.moveToFastButton->setEnabled( false );
	ui.moveToMassButton->setEnabled( false );
}

ssm::~ssm()
{
	delete fastViewModel;
	delete massViewModel;
}

void ssm::on_moveToFastButton_clicked()
{
	QModelIndexList indices = ui.massStorageView->selectionModel()->selectedIndexes();
	while( indices.size() ) {
		QModelIndex toRemove = indices.first();
		int newRow = fastViewModel->rowCount();

		fastViewModel->insertRow( newRow );
		fastViewModel->setData( fastViewModel->index( newRow ), toRemove.data() );
		
		massViewModel->removeRow( toRemove.row() );

		indices = ui.massStorageView->selectionModel()->selectedIndexes();
	}

	fastViewModel->sort( 0 );
}

void ssm::on_moveToMassButton_clicked()
{
	QModelIndexList indices = ui.fastStorageView->selectionModel()->selectedIndexes();
	while( indices.size() ) {
		QModelIndex toRemove = indices.first();
		int newRow = massViewModel->rowCount();

		massViewModel->insertRow( newRow );
		massViewModel->setData( massViewModel->index( newRow ), toRemove.data() );

		fastViewModel->removeRow( toRemove.row() );

		indices = ui.fastStorageView->selectionModel()->selectedIndexes();
	}

	massViewModel->sort( 0 );
}

void ssm::on_fastStorageView_clicked()
{
	ui.moveToFastButton->setEnabled( false );
	ui.moveToMassButton->setEnabled( true );
}

void ssm::on_massStorageView_clicked()
{
	ui.moveToFastButton->setEnabled( true );
	ui.moveToMassButton->setEnabled( false );
}