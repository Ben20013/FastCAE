#ifndef GEOMETRYDATA_H
#define GEOMETRYDATA_H

#include "geometryAPI.h"
#include <QString>
#include <QList>
#include <QStringList>
#include "DataProperty/DataBase.h"

class TopoDS_Shape;
class QDomDocument;
class QDomElement;
class QDomNodeList;
class gp_Ax3;

namespace Geometry
{
	class GeometrySet;
	class GeometryDatum;

	class GEOMETRYAPI GeometryData : public DataProperty::DataBase 
	{
	public:
		//获取单例指针
		static GeometryData* getInstance();
		//添加形状
		void appendGeometrySet(GeometrySet* set);
		//添加基准
		void appendGeometryDatum(GeometryDatum* datum);
		//获取全部基准
		QList<GeometryDatum*> getGeometryDatum();
		//获取形状数量
		int getGeometrySetCount();
		//几何数据是否为空
		bool isEmpty();
		//获取第index个形状
		GeometrySet* getGeometrySetAt(const int index);
		//根据形状获取索引
		int getIndexByGeoometrySet(GeometrySet* s);
		//移除第index个形状
		void removeGeometrySet(const int index);
		//替换形状
		void replaceSet(GeometrySet* newset, GeometrySet* oldset);
		//移除最顶层的形状，区别于递归包含的子形状
		void removeTopGeometrySet(GeometrySet* set);
		//是否存在这个形状，递归子形状全部查找
		bool hasGeometrySet(GeometrySet* set);
//		void removeDatumPlaneByIndex(int index);
		//移除基准
		void removeGeometryDatum(GeometryDatum* datum);
		//设置可见性，不涉及子形状
		void setVisable(int index, bool visable);
		//清空全部数据
		void clear();
		//根据ID查找形状，递归子形状查找
		GeometrySet* getGeometrySetByID(const int id);
		//获取第index个子形状
		GeometryDatum* getDatumPlaneByIndex(const int index);
		QString getMD5();
		//根据ID排序
		void sort();
		///文件写出至工程文件
		QDomElement& writeToProjectFile(QDomDocument* doc, QDomElement* element, bool isdiso = false);
		///从工程文件读入数据
		void readFromProjectFile(QDomNodeList* nodelist , bool isdiso = false);
		//设置曹绘平面
		void setSketchPlane(double* loc, double* dir);
		//获取
		gp_Ax3* getSketchPlane();

	private:
		GeometryData() = default;
		~GeometryData();

	private:
		static GeometryData* _instance;
		QList<GeometrySet*> _geometryList{};
		QList<GeometryDatum*> _geomtretryDatumList{};
		gp_Ax3* _sketchPlan{};
	};

	bool compareSet(GeometrySet* s1, GeometrySet* s2);

}

#endif
