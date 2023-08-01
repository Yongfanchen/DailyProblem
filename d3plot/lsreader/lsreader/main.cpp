#include "lsreader.h"
#include <QtWidgets/QApplication>
#include "d3plotreader.h"
#include "binoutreader.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <QFileDialog>
#define PI 3.141592653589793

using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 打开文件对话框
	QString file_path = QFileDialog::getOpenFileName(nullptr, "Open d3plot File", "", "All Files (*.*)");
	if (file_path.isEmpty())
	{
		std::cout << "No file selected." << std::endl;
		return 0;
	}
	string d3plot = file_path.toStdString();

	string::size_type pos = d3plot.find('/');

	while (pos != string::npos)
	{
		d3plot.replace(pos, 1, "\\");
		pos = d3plot.find('/');
	}

	D3plotReader dr(d3plot.c_str());

	int num_nodes = 0;
	dr.GetData(D3P_NUM_NODES, (char*)&num_nodes);

	int num_states = 0;
	dr.GetData(D3P_NUM_STATES, (char*)&num_states);

	D3P_Parameter param;
	param.ist = num_states - 1;

	D3P_Vector* node_ini_coor = new D3P_Vector[num_nodes];
	dr.GetData(D3P_NODE_INITIAL_COORDINATES, (char*)node_ini_coor);
	vector<vector<float>> node_in_coor;
	for (size_t i = 0; i < num_nodes; i++)
	{
		vector<float> coor;
		coor.push_back(node_ini_coor[i].X());
		coor.push_back(node_ini_coor[i].Y());
		coor.push_back(node_ini_coor[i].Z());
		node_in_coor.push_back(coor);
	}


	D3P_Vector* node_coor = new D3P_Vector[num_nodes];
	dr.GetData(D3P_NODE_COORDINATES, (char*)node_coor, param);
	vector<vector<float>> node_coor1;
	for (size_t i = 0; i < num_nodes; i++)
	{
		vector<float> coor1;
		coor1.push_back(node_coor[i].X());
		coor1.push_back(node_coor[i].Y());
		coor1.push_back(node_coor[i].Z());
		node_coor1.push_back(coor1);
	}


   
    //lsreader w;
    //w.show();

    return a.exec();
}
