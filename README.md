#ofxLibRocket

NOTICE: This branch uses the new ofParameter which is only available in the develop branch

##about

ofxLibRocket is a wrapper around the excellent librocket library (http://librocket.com/), an html and css layouting engine for c++.  
This means that you can layout rectangular elements within c++ the same way you would on a web site.
The wrapper tries to do the integration with openframeworks as easy as possible and is built for openframeworks 0072.

##screenshot of the example
The following is a two column layout that automatically resizes to fill the entire window.  

![alt text](http://uploads.undef.ch/ofxLibRocket/shot1.jpg "screenshot")

##features
- html loading for content
- css loading for styling
- custom elements
- gui elements (not complete yet)
- scrolling
- full debugger that works similar to web inspectors in browsers

##platforms
libRocket is cross platform (win / linux / os x / ios / android).    
ofxLibRocket is mainly developed on ubuntu linux 64bit. It does already contain compiled libRocket libraries for os x as well. There is also an XCode project for the example but it might be outdated.  
There are currently no precompiled libraries for windows. But libRocket is mainly developed on windows so it should be easy to create the appropriate a file.

##custom elements
One core feature is the easy creation of custom elements that play nicely with the rest of openframeworks. You can create one by extending ofxLibRocketCustomElement.

```c++
class View : public ofxLibRocketCustomElement
{
public:
  void setup();
  void update();
  void draw();

  void onMouseMove(int x, int y);
  void onMousePress(int x, int y, int button);
  void onMouseUp(int x, int y, int button);
  void onMouseDrag(int x, int y, int button);
  void onMouseEnter(int x, int y);
  void onMouseOut(int x, int y);
}
```

Now this class can be registered to the engine with a tag name.
```c++
  libRocket.addCustomElement<View>("view");
```

This tag name is now usable within the html document.
```html
<html>
  <head>
		<title>Demo</title>
		<link type="text/rcss" href="controls.css"/>
		<link type="text/rcss" href="style.css"/>
	</head>
	<body>
		<div id="views"
  		<!-- this will create two instances of the View class with a title in them -->
			<view class="first" id="view1">
				<h1>VIEW 1</h1>
			</view>
			<view>
				<h1>VIEW 2</h1>
			</view>
		</div>
	</body>
</html>
```
Style the way whatever way you want to in your css
```css
view{
  width: 50%;
  height: 50%;
  display: block;
  background-color: black;
  float: left;
  color: white;
}

view.first{
	background-color: #000;
	color: #ff00ff;	
}
```

Pointers to these view instances can be retrieved from c++ as follows
```c++
//load the demo document
doc = libRocket.loadDocument("demo.html");

//get all the views into a custom vector
ofxLibRocketElementList_<View> views = doc->getElementsByTagName<View>("view");

//get a single View by its ID
View* view1 = doc->getElementById<View>("view1");

//hide the view for example
view1->hide();
```

See the example for more details.

##gui elements
LibRocket already comes with a few gui elements like buttons, sliders, dropdown selects, textfields. Sliders and buttons are wrapped within ofxLibRocket but the wrapping could be better and is subject to change.
So it is not recommended to depend on those just yet.  
More elements are planned to be integrated as custom elements by ofxLibRocket itself. (Things like 2d slider, 3d render viewport, video fields, etc. - I'm open for ideas there)

##quirks and issues
###casting
One main issue is that depending on your usage, there is some casting going on.
The reason for this is that in such an open system where a new class can be registered and identified by a string, it is impossible to keep all elements in dedicated containers.
They all have to be stored at one global location as their super class.  
ofxLibRocket provides templated functions to make the casting as easy and seamless as possible but bear in mind that it does happen in the background.
###tag names have to be all lowercase
Camelcase tag names do not work. So instead of viewContainer, write viewcontainer or view-container.
