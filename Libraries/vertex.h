#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
	protected:
		string name;
		int numVertex;
		
	public:
		Vertex(){}
		
		Vertex(string name){
			this->name = name;
			numVertex=-1;
		}
		
		Vertex(string name, int numVertex){
			this->name=name;
			this->numVertex = numVertex;
		}
		
		void setName(string name){ this->name = name; }
		
		void setNumVertex(int numVertex){ this->numVertex = numVertex; }
		
		string getName(){ return this->name; }
		
		int getNumVertex(){	return this->numVertex;	}
		
		bool similar(Vertex v){	return v.name == this->name; }
		
		bool similar(string v){	return v == this->name;	}
		
};

#endif
