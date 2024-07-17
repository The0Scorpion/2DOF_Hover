#ifndef ACTIONS_BUFFER_H
#define ACTIONS_BUFFER_H
#define ActionSize 2000
extern int actionsBuffer[ActionSize][2]; // Declaration in ActionsBuffer.cpp or main.ino

void initializeActionsBuffer() {
    // Initialize actionsBuffer as needed
    for(int i=0;i<ActionSize;i++){
        actionsBuffer[i][0]=-1000;
        actionsBuffer[i][1]=-1000;
    }
}

void addAction(int index, int xAction, int yAction) {
    actionsBuffer[index][0] = xAction;
    actionsBuffer[index][1] = yAction;
}

int getRemainingActions(int curIndex) {
    // Implement logic to calculate remaining actions in buffer
    int count = 0;
    for (int i = curIndex; i < 1000; i++) {
        if (actionsBuffer[i][0] != -1000 || actionsBuffer[i][1] != -1000) {
            count++;
        } else {
            break; // Assuming actions are contiguous
        }
    }
    return count;
}

#endif // ACTIONS_BUFFER_H
