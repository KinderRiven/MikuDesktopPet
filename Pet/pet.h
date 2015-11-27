#ifndef PET_H
#define PET_H

#include <QtWidgets/QMainWindow>
#include "ui_pet.h"
#include "kHeader.h"
#include "ktalk.h"
#include "kSetting.h"

class Pet : public QMainWindow{
	Q_OBJECT

public:
	void kShow(bool ok);
	void loadImage();									//�ı䶯���ĺ���
	void loadAction();									//Ԥ����
	Pet(QWidget *parent = 0);
	~Pet();

	void menuExit();									//�˳��źŲ�
	void menuStand();
	void menuFree();
private slots:
	void changeState();									
	void changeAction();
private:	
	void paintEvent(QPaintEvent*);						//�ػ�
	void mousePressEvent(QMouseEvent *event);			//�������д
	void mouseMoveEvent(QMouseEvent *event);			//����ƶ���д
	void contextMenuEvent(QContextMenuEvent *event);	//��д��������

private:	
	Ui::PetClass ui;
	kTalk   talk;

	QTimer  imageTimer;			//
	QTimer  stateTimer;			//

	QPixmap image;

	QPoint  preMousePos;

	int imageID;					//ͼƬID
	int stateID;					//״̬ID
	int	actionID;					//����ID
	bool stateChange;				//�Ƿ���Ըı�״̬

	QAction *menuAction[32];		//�˵���ָ��
	vector<int>actionVector[15];	//��������
};

#endif // PET_H
