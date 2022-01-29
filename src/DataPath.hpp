#ifndef DATAPATH
#define DATAPATH

#include "Topology.hpp"
#include <map>

//void AddDataPath(DataPath* p, int orientation);
#define SYS_TOPO_DATAPATH_NONE 1
#define SYS_TOPO_DATAPATH_OUTGOING 2
#define SYS_TOPO_DATAPATH_INCOMING 4

//int oriented
#define SYS_TOPO_DATAPATH_BIDIRECTIONAL 8
#define SYS_TOPO_DATAPATH_ORIENTED 16

//dp_type
#define SYS_TOPO_DATAPATH_TYPE_NONE 64
#define SYS_TOPO_DATAPATH_TYPE_LOGICAL 64
#define SYS_TOPO_DATAPATH_TYPE_PHYSICAL 128
#define SYS_TOPO_DATAPATH_TYPE_L3CAT 256

using namespace std;
class Component;
class DataPath;

DataPath* NewDataPath(Component* _source, Component* _target, int _oriented, int _type = SYS_TOPO_DATAPATH_TYPE_NONE);
DataPath* NewDataPath(Component* _source, Component* _target, int _oriented, double _bw, double _latency);
DataPath* NewDataPath(Component* _source, Component* _target, int _oriented, int _type, double _bw, double _latency);

class DataPath {

public:
    DataPath(Component* _source, Component* _target, int _oriented, int _type = SYS_TOPO_DATAPATH_TYPE_NONE);
    DataPath(Component* _source, Component* _target, int _oriented, double _bw, double _latency);
    DataPath(Component* _source, Component* _target, int _oriented, int _type, double _bw, double _latency);

    Component* GetSource();
    Component* GetTarget();

    void Print();
    map<string,void*> metadata;
private:
    Component * source;
    Component * target;

    const int oriented;
    const int dp_type;

    double bw;
    double latency;

};

#endif
