#include "delaybuffer.h"

nBlock_DelayBuffer::nBlock_DelayBuffer() {
    return;
}

void nBlock_DelayBuffer::triggerInput(nBlocks_Message message) {
    if (message.inputNumber == 0) {
		switch (message.dataType) {
			case OUTPUT_TYPE_FLOAT:
				output[0] = PackFloat(message.floatValue);
				available[0] = 1;
				break;

			case OUTPUT_TYPE_INT:
				output[0] = message.intValue;
				available[0] = 1;
				break;

			case OUTPUT_TYPE_STRING:
				output[0] = (uint32_t)message.stringValue;
				available[0] = 1;
				break;

			case OUTPUT_TYPE_ARRAY:
				output[0] = (uint32_t)message.pointerValue;
				available[0] = 1;
				break;
		}
    }
}
