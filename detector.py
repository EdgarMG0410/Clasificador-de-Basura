import cv2
import serial

cap = cv2.VideoCapture(0,cv2.CAP_DSHOW)
haar = cv2.CascadeClassifier('coca.xml')
haar2 = cv2.CascadeClassifier('agua.xml')
font = cv2.FONT_HERSHEY_SIMPLEX
arduino = serial.Serial("COM6",9600)

while True:
    ret,frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    aluminio = haar.detectMultiScale(gray,
        scaleFactor = 4,
        minNeighbors = 91,
        minSize=(70,78))
    
    for (x,y,w,h) in aluminio:
        pt1=(x,y)
        pt2=(x+w,y+h)
        cv2.rectangle(frame, (x,y),(x+w,y+h),(255,0,0),2)
        cv2.rectangle(frame,(x,y),(x+100,y+40),(255, 0, 0),-1)
        cv2.putText(frame,
            'Aluminio',
            (x+10,y+30),
            font, 0.7,
            (255,255,255),2
            )
        print("Aluminio!!")
        arduino.write(b'y')
    plastico = haar2.detectMultiScale(gray,
        scaleFactor = 4,
        minNeighbors = 90,
        minSize=(70,78))
    
    for (x,y,w,h) in plastico:
        pt1=(x,y)
        pt2=(x+w,y+h)
        
        cv2.rectangle(frame, (x,y),(x+w,y+h),(255,0,0),2)
        cv2.rectangle(frame,(x,y),(x+100,y+40),(255, 0, 0),-1)
        cv2.putText(
            frame,'Plastico',
            (x+10,y+30),
            font, 0.7,
            (255,255,255),2
            )
        print("Plastico!!")
        arduino.write(b'n')
        
    cv2.imshow('VIdeo',frame) 
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    
cap.release()
cv2.destroyAllWindows()

