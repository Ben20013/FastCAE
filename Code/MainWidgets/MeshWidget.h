#ifndef MESHWIDGET_H
#define MESHWIDGET_H

#include <QTreeWidget>
#include "preWindow.h"

namespace MeshData
{
	class MeshData;
	class MeshSet;
	class MeshKernal;

}

namespace GUI
{
	class MainWindow;
}
namespace DataProperty
{
	class DataBase;
}


class QTreeWidgetItem;

namespace MainWidget
{

	class MeshWidget : public QTreeWidget
	{
		Q_OBJECT
	public:
		MeshWidget(GUI::MainWindow* mw, QWidget* parent = nullptr);
		~MeshWidget();
		//注册开放可用接口
		void registerEnabledModule();

	signals:
		//更新显示状态
		void updateDisplay(int index,bool visable);
		//移除第index个Kernal
		void removeMeshData(int index);
		//高亮组件
		void higtLightSet(MeshData::MeshSet* set);
		//高亮Kernal
		void higtLightKernal(MeshData::MeshKernal* k);
		//更新属性
		void disPlayProp(DataProperty::DataBase* pops);
		//更新状态
		void updateActionStates();
		//显示参数窗体
		void dispalyParaWidget(QWidget*);
		void updatePreMeshActor();
		void startMesherPySig(QString mesher);
		//清除高亮
		void clearHighLight();

	public slots :
		//更新树
		void updateTree();
		//更新网格kernal子树
		void updateMeshTree();
		//更新组件子树
		void updateMeshSetTree();
		//鼠标单击事件
		void singleClicked(QTreeWidgetItem*, int);
		//移除当前Kernal
		void removeMeshData();
		///移除当前组件
		void removeSetData();

	private slots:
		void startMesher(QString mesher);
		//隐藏全部
		void hideAll();
		//显示全部
		void showAll();
		//合并与切除
		void mergeSet();
		//重命名
		void rename();
		//节点状态改变
		void itemStatesChanged(QTreeWidgetItem*, int);

	private:
		void contextMenuEvent(QContextMenuEvent *event) override;

	private:
		GUI::MainWindow* _mainWindow{};
		MeshData::MeshData* _data{};
		QTreeWidgetItem* _meshRoot{};
		QTreeWidgetItem* _setRoot{};
		QTreeWidgetItem* _currentItem{};
	};

}

#endif
