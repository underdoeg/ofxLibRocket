#ifndef OFXLIBROCKETCONTROLBASE_H
#define OFXLIBROCKETCONTROLBASE_H

#include "ofxLibRocketCustomElement.h"

template <class T>
class ofxLibRocketControlBase: public ofxLibRocketCustomElement {
public:
	ofxLibRocketControlBase();
	T getValue();
	void setName(string name);
	void setValue(T);
	void setParameter(ofParameter<T> param);
	//ofParameter<T> getParameter();
protected:
	virtual void valueChanged(T val) = 0;

private:
	void registerListener();
	void unregisterListener();
	void onValueChange(T& value);

	ofParameter<T> param;
};

template <class T>
ofxLibRocketControlBase<T>::ofxLibRocketControlBase(){
	registerListener();
}


template <class T>
T ofxLibRocketControlBase<T>::getValue(){
	return param.get();
}

template <class T>
void ofxLibRocketControlBase<T>::setValue(T val){
	param = val;
}

template <class T>
void ofxLibRocketControlBase<T>::onValueChange(T& val){
	valueChanged(val);
}

template <class T>
void ofxLibRocketControlBase<T>::registerListener(){
	param.addListener(this, &ofxLibRocketControlBase<T>::onValueChange);
}

template <class T>
void ofxLibRocketControlBase<T>::unregisterListener(){
	param.removeListener(this, &ofxLibRocketControlBase<T>::onValueChange);
}


#endif // OFXLIBROCKETCONTROLBASE_H
