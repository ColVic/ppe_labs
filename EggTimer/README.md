# Cocoa (API). Swift
---
Cocoa is Apple's native object-oriented application programming interface (API) for their operating systems (macOS, iOS, ...).

Cocoa consists of three Objective-C object libraries called frameworks:
- **Foundation Kit (Foundation)** - is a generic object-oriented library providing string and value manipulation, containers and iteration, distributed computing, event loops (run loops), and other functions that are not directly tied to the graphical user interface.
- **Application Kit (AppKit)** - It contains code programs can use to create and interact with graphical user interfaces. AppKit is built on top of Foundation, and uses the same NS prefix.
- **Core Data** - is the object persistence framework included with Foundation and Cocoa and found in Cocoa.h.

I choose to make my laboratories in Cocoa API due to its simplicity and small simillarities with MVC principles.

The **NSController** family of classes provide predefined behavior for the controller layer. These classes are considered part of the Cocoa Bindings system, which also makes extensive use of protocols such as **Key-Value Observing** and **Key-Value Binding**. The term 'binding' refers to a relationship between two objects, often between a view and a controller.

**Core Data** framework standardizes change tracking and persistence in the model layer. In effect, the framework greatly simplifies the process of making changes to application data, undoing changes when necessary, saving data to disk, and reading it back in.

**NSViewController** manages a view, typically loaded from a nib file. View controllers are responsible for hooking up the model layer to the view layer, and have an incredibly important role in the architecture of macOS app.


#  EggTimer, ViewControllers, Models and UI
---
## Xcode

|![Screen Shot 2018-06-08 at 17.22.41.png](quiver-image-url/851BF937C4F361517102E6A449D1A9D7.png =1085x682)|
|:-:|
|**Fig. 1**|

Xcode creates the basic template for Cocoa apps. On run, we can see a simple blank window:
|![Screen Shot 2018-06-08 at 17.24.43.png](quiver-image-url/DC87291DE325B2FC1E53FF1793CD6A8E.png =483x295)|
|:-:|
|**Fig. 2**|

- The window is resizable, it can be minimized and made full screen.
- There is a complete set of menus, many of which already work without you doing anything.
- The Dock icon has the usual menus.

For this single blank window is reponsible the following class:
## class NSWindow
A single NSWindow object corresponds to at most one onscreen window. The two principal functions of a window are to provide an area in which views can be placed and to accept and distribute, to the appropriate views, events the user instigates through actions with the mouse and keyboard.

Here are some useful methods described in this class:
### Methods:
---
```
convenience init(contentViewController: NSViewController)
```
**Params:**
- **contentViewController**
The view controller that provides the main content view for the window. The window’s contentView property is set to contentViewController.view.

**Return value:**
- A window with the content view controller set to the passed-in view controller object.

This method creates a basic window object that is titled, closable, resizable, and miniaturizable. By default, the window's title is automatically bound to the title of contentViewController. You can control the size of the window by using Auto Layout and applying size constraints to the view or its subviews. The initial size of the window is set to the initial size of contentView (that is, the size of contentViewController.view). The newly created window has isReleasedWhenClosed set to false, and it must be explicitly retained to keep the window instance alive.

---

```swift
init(
contentRect: NSRect,
styleMask style: NSWindow.StyleMask,
backing backingStoreType: NSWindow.BackingStoreType,
defer flag: Bool
)
```
**Params:**
- **contentRect**
Origin and size of the window’s content area in screen coordinates. Note that the window server limits window position coordinates to ±16,000 and sizes to 10,000.
- **style**
The window’s style. It can be NSBorderlessWindowMask, or it can contain any of the options described in NSWindow.StyleMask, combined using the C bitwise OR operator.
- **backingStoreType**
Specifies how the drawing done in the window is buffered by the window device, and possible values are described in NSWindow.BackingStoreType.
- **flag**
Specifies whether the window server creates a window device for the window immediately. When true, the window server defers creating the window device until the window is moved onscreen. All display messages sent to the window or its views are postponed until the window is created, just before it’s moved onscreen.

This method is the designated initializer for the NSWindow class.
Deferring the creation of the window improves launch time and minimizes the virtual memory load on the window server.
The new window creates a view to be its default content view. You can replace it with your own object by setting the contentView property.

---
```swift
convenience init(
contentRect: NSRect,
styleMask style: NSWindow.StyleMask,
backing backingStoreType: NSWindow.BackingStoreType,
defer flag: Bool,
screen: NSScreen?
)
```


## Adding the UI
---

I decided to create an EggTimer application for macOS in order to understand the solid principles of Cocoa API and gain some practical knowledge about Event-Driven Programming. This app is supposed to offer a variety of options from **Preferences** window in order to boil the perfect egg. As the sime passes, egg image changes its color, making the UI a little more interactive.

The UI is added from `Main.storyboard` interface from project navigator tab:

|![Screen Shot 2018-06-10 at 10.23.32.png](quiver-image-url/CD425593431AAC16B1F6256C77C5E656.png =1495x792)|
|:-:|
|**Fig. 3**|

Visual elements are linked from `Main.storyboard` to code using `@IBOutlet`. This is short for Interface Builder Outlet and is how you tell the storyboard editor that these object names are available for linking to a visual object.
For the button, the code needs to know when a user clicks the button. This calls for an `@IBAction` instead of an `@IBOutlet`.

|![Screen Shot 2018-06-10 at 10.27.57.png](quiver-image-url/2A3C68FB09D857443ABDD7134CCC3CD8.png =534x904)|
|:-:|
|**Fig. 4**|

In Fig.4 is shown a part of code from my `ViewController.swift` file where are declared the necessary fields, buttons, and some actions of my interface.

Because I one more window called **Preferences**, there is also a controller attacked to it.

|![Screen Shot 2018-06-10 at 10.38.01.png](quiver-image-url/3B648DB8DB9B3369B05DB9D2BD6F341C.png =565x812)|
|:-:|
|**Fig. 5**|

In Fig.5 is shown a part of code from my `PrefsViewController.swift`


Each controller has a default method called `viewDidLoad()`. This method is called after the view controller has loaded its view hierarchy into memory. This method is called regardless of whether the view hierarchy was loaded from a nib file or created programmatically in the loadView() method. You usually override this method to perform additional initialization on views that were loaded from nib files.

In my case, for `ViewController.swift` I called the initial setup params when the view loaded in order to show the last setting that user prefered to use.

## Application Delegates
---

In Cocoa API, the object which is repsonsible for event-handling is called **Delegate**. The delegating object is often a responder object—that is, an object inheriting from NSResponder in AppKit or UIResponder in UIKit—that is responding to a user event. The delegate is an object that is delegated control of the user interface for that event, or is at least asked to interpret the event in an application-specific manner.

The programming mechanism of delegation gives objects a chance to coordinate their appearance and state with changes occurring elsewhere in a program, changes usually brought about by user actions. More importantly, delegation makes it possible for one object to alter the behavior of another object without the need to inherit from it. The delegate is almost always one of programmer's custom objects, and by definition it incorporates application-specific logic that the generic and delegating object cannot possibly know itself.

|![Screen Shot 2018-06-10 at 10.48.50.png](quiver-image-url/811E50898D8AEE4C2D6A263651BBAE2B.png =633x579)|
|:-:|
|**Fig. 6**|

In Fig.6 is represented my `AppDelegate.swift` file which is repsonsible for setting up the initial menu buttons (Start, Stop, Reset).

## Models
---

|![Screen Shot 2018-06-10 at 11.36.19.png](quiver-image-url/88C6C1B9BF2092E937B19AEF8A10F6E0.png =707x850)|
|:-:|
|**Fig. 7**|

In Fig.7 we have a small representation of the main model which is class called **EggTimer**. This class has properties for the start time of the timer, the requested duration and the elapsed time. It also has a Timer object that fires every second to update itself. Methods will start, stop, resume or reset the EggTimer object.

The EggTimer model class holds data and performs actions, but has no knowledge of how this is displayed. The Controller (in this case ViewController), knows about the EggTimer class (the Model) and has a View that it can use to display the data.

To communicate back to the ViewController, EggTimer uses a delegate protocol. When something changes, the EggTimer sends a message to its delegate. The ViewController assigns itself as the EggTimer's delegate, so it is the one that receives the message and then it can display the new data in its own View.

**Preferences** model is going to be slighly different. Preferences are going be stored using UserDefaults which is a key-value way of storing small pieces of data in the Preferences folder in the app's Container.

|![Screen Shot 2018-06-10 at 11.33.31.png](quiver-image-url/08880162057EF12D1C4BA162070DC34F.png =702x497)|
|:-:|
|**Fig. 8**|

1. A computed variable called **selectedTime** is defined as a **TimeInterval**.
2. When the value of the variable is requested, the **UserDefaults** singleton is asked for the Double value assigned to the key "selectedTime". If the value has not been defined, **UserDefaults** will return zero, but if the value is greater than 0, return that as the value of **selectedTime**.
3. If **selectedTime** has not been defined, use the default value of 360 (6 minutes).
4. Whenever the value of **selectedTime** is changed, write the new value to **UserDefaults** with the key "selectedTime".

So by using a computed variable with a getter and a setter, the UserDefaults data storage will be handled automatically.

## Conclusion:
---
While creating EggTimer application I learned how to correctly operate with windows, child windows and interchange information between them through controllers. I learned how to draw elements and align them in order to obtain a responsive design. I learned how to use the system timer and change elements depending on its value.




