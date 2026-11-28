const windows = workspace.stackingOrder;

// Get all the window names
// More about the window API:
// https://develop.kde.org/docs/plasma/kwin/api/#kwinwindow
// for (let w of windows) {
//   print(w.caption);
// }

// Get the current desktop
// print(workspace.currentDesktop);

// Get the name of the desktop
// print(workspace.currentDesktop.name);

// Get the number of the desktop
// print(workspace.currentDesktop.x11DesktopNumber);

// Test if window is on current desktop
// const curDesktop = workspace.currentDesktop
//
// for (let w of windows) {
//   if (w.desktops[0] == curDesktop) {
//       print(w.caption + " is on current desktop")
//   }
// }

// Check if window is excluded from capture
const curDesktop = workspace.currentDesktop

for (let w of windows) {
  if (w.desktops[0] == curDesktop) {
    if (w.excludeFromCapture == true) {
      w.excludeFromCapture = false
    }
  }
}
