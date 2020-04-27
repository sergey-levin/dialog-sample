# dialog-sample
Minimum example for possible double delete in QtCreator settings widget.

# Preparations
Linux or OS X is needed to run sample test.sh file.
1. Check run permissions for test.sh. If not: chmod +x test.sh
2. Compile project.

# How to use
1. Run the app.
2. Press "Show settings" button.
3. In dialog press "Apply", then fast press Esc key.
4. The app should crash.

Uncomment DEFINES += NO_CRASH in .pro file to avoid crash.
