.model small
.stack 100h

DATA SEGMENT
    header DB 0Ah, 0Dh,0Ah, 0Dh,"             - H O S P I T A L    E M E R G E N C Y    W A R D -$"
    options db 0Ah, 0Dh,0Ah, 0Dh, '1. Add Patient', 0Ah, 0Dh, '2. Remove Patient', 0Ah, 0Dh, '3. Display Ward', 0Ah, 0Dh, '4. Exit', 0Ah, 0Dh, '$'
    patientName DB 100 DUP ('$')
    birthDate DB 100 DUP ('$')
    bloodGroup DB 100 DUP ('$')
    condition DB 100 DUP('$')
    patientCount DW 0
    patientsData DB 500 DUP ('$')
    patientQueue Dw 500 DUP ('$')
    patientQueueSize DW 0
    prompt DB 0Ah, 0Dh, "Enter the Desired Option : $"
    addPatientHeader DB 0Ah, 0Dh, 0Ah, 0Dh,"                          - A D D    P A T I E N T -$"
    promptName DB 0Ah, 0Dh, "Enter the Patient's Name : $"
    promptBirthDate DB 0Ah, 0Dh, "Enter the Date of Birth : $"
    promptBloodGroup DB 0Ah, 0Dh, "Enter the Blood Group : $"
    conditions DB 0Ah, 0Dh, 0Ah, 0Dh,"                  - C O N D I T I O N S -", 0Ah, 0Dh
               DB "1. Unresponsive", 0Ah, 0Dh
               DB "2. Respiratory Arrest", 0Ah, 0Dh
               DB "3. Unconscious", 0Ah, 0Dh
               DB "4. Major Trauma", 0Ah, 0Dh
               DB "5. Shock", 0Ah, 0Dh, '$'
    promptCondition DB 0Ah, 0Dh, "Enter the Condition : $"
    invalidInput DB 0Ah, 0Dh, "Invalid Input! Please Input Again. $"
    invalidName DB 0Ah, 0Dh, "Invalid Input. Please Enter the Name in Valid Format. $"
    invalidBirthDate DB 0Ah, 0Dh, "Invalid Input. Please Enter the Birthdate in Valid Format. $"
    invalidBloodGroup DB 0Ah, 0Dh, "Invalid Input. Please Enter the Blood Group in Valid Format. $"
    invalidCondition DB 0Ah, 0Dh, "Invalid Input. Please Enter the Condition in Valid Format. $"
    invalidPriority DB 0Ah, 0Dh, "Invalid Input. Please Enter the Priority in Valid Format. $"
    addPatientMsg DB 0Ah, 0Dh, "Adding patient... $"
    removePatientMsg DB 0Ah, 0Dh, "Removing patient... $"
    displayWardMsg DB 0Ah, 0Dh, "Displaying Ward: $"
    exitMsg DB 0Ah, 0Dh, "Exiting. $"
DATA ENDS 

DISPLAY_PAT_NAME MACRO INDEX, PT
    
    MOV AH, 02H
    MOV AL, BYTE PTR []
ENDM

DISPLAY_PATIENT MACRO index
    mov ah,02h
    ;MOV AL, BYTE PTR [patientsData+index]   ; Load condition
    ; Display condition (e.g., print or output to the desired output device)
    
    mov dl, 0ah
    int 21h
    mov dl, 0dh
    int 21h
    
    LEA SI, [patientsData+index+48]          ; Load address of patient's name
    ; Display patient's name  
    mov DL, [SI]
    int 21h
    
     
    LEA SI, [patientName+index+2]        ; Load address of patient's birth date
        ; Display patient's birth date     
    mov DL, [SI]
    int 21h
     LEA SI, [patientName+index+3]        ; Load address of patient's birth date
        ; Display patient's birth date     
    mov DL, [SI]
    int 21h
     LEA SI, [patientName+index+4]        ; Load address of patient's birth date
        ; Display patient's birth date     
    mov DL, [SI]
    int 21h    
            
    
    
    
    LEA SI, [birthDate+index+2]        ; Load address of patient's blood group
    ; Display patient's blood group 
    mov DL, [SI]
    int 21h 
    
    LEA SI, [bloodGroup+index+2]        ; Load address of patient's blood group
    ; Display patient's blood group 
    mov DL, [SI]
    int 21h
ENDM



CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX
    
    ; Print the header
    LEA DX, header
    MOV AH, 09h
    INT 21h
    
    MENU:
    ; Print the menu options
    LEA DX, options
    MOV AH, 09h
    INT 21h
    
    ; Prompt for user input
    LEA DX, prompt
    MOV AH, 09h
    INT 21h
    
    ; Read the option
    MOV AH, 01h
    INT 21h
    
    CMP AL, '1'
    JE ADD_PATIENT
    
    CMP AL, '2'
    JE REMOVE_PATIENT
    
    CMP AL, '3'
    JE DISPLAY_WARD
    
    CMP AL, '4'
    JE EXIT
    
    ; Invalid option, loop back to the menu
    LEA DX, invalidInput
    MOV AH, 09h
    INT 21h
    JMP MENU
    
ADD_PATIENT:  
    ; Print the add patient header
    LEA DX, addPatientHeader
    MOV AH, 09h
    INT 21h

        ; Prompt for patient's name
        LEA DX, promptName
        MOV AH, 09h
        INT 21h
    
    
        ; Read the patient's name
        LEA DX, patientName
        MOV AH, 0Ah
        MOV DX, offset patientName
        INT 21h
    
 
    ; Prompt for patient's birth date
    LEA DX, promptBirthDate
    MOV AH, 09h
    INT 21h
    
    ; Read the patient's birth date
    LEA DX, birthDate
    MOV AH, 0Ah
    MOV DX, offset birthDate
    INT 21h
    
    
    
    ; Prompt for patient's blood group
    LEA DX, promptBloodGroup
    MOV AH, 09h
    INT 21h
    
    ; Read the patient's blood group
    LEA DX, bloodGroup
    MOV AH, 0Ah
    MOV DX, offset bloodGroup
    INT 21h
    
    ; Prompt for patient's condition
    LEA DX, conditions
    MOV AH, 09h
    INT 21h
    
    ; Read the patient's condition
    LEA DX, promptCondition
    MOV AH, 09h
    INT 21h
    
    ; Read the condition index
    MOV AH, 01h
    INT 21h
    
    SUB AL, '0' 
    
    MOV condition, Al
    
    ; Add patient to the queue
    MOV AX, patientCount
    MOV BX, 2 ; Multiply by 2 to account for the byte size of each patient
    MUL BX
    
    MOV SI, AX
    MOV DI, SI
    ADD DI, 2 ; Skip the patient count bytes
    
    ; Store patient data
    MOV AL, condition
    MOV [patientsData+SI], AL 
    
    MOV AX, PatientCount
    MOV SI,AX
    
    LEA SI, [patientName+[SI]]
    LEA DI, [patientsData+DI]
    MOV DI, SI
    INC SI
    INC DI
    

    LEA SI, [birthDate+SI]
    LEA DI, [patientsData+DI]
    MOV DI, SI
    INC SI
    INC DI
    
    LEA SI, bloodGroup
    LEA DI, [patientsData+DI]
    MOV DI, SI
    INC SI
    INC DI
    
    INC patientCount
    INC [SI]
    ; Print adding patient message
    LEA DX, addPatientMsg
    MOV AH, 09h
    INT 21h
    
    JMP MENU
    
REMOVE_PATIENT:
    ; Print removing patient message
    LEA DX, removePatientMsg
    MOV AH, 09h
    INT 21h
    
    ; Prompt for patient's name
    LEA DX, promptName
    MOV AH, 09h
    INT 21h
    
    ; Read the patient's name
    LEA DX, patientName
    MOV AH, 0Ah
    MOV DX, offset patientName
    INT 21h
    
    ; Search for the patient in the queue
    MOV CX, patientCount
    MOV SI, 2 ; Skip the patient count bytes
    MOV DI, SI
    
    SEARCH_LOOP:
    CMP CX, 0
    JE PATIENT_NOT_FOUND
    
    ; Compare patient name
    LEA SI, [patientsData+DI]
    LEA DI, patientName
    MOVSB
    
    LEA SI, [patientsData+DI+2]
    LEA DI, patientName+2
    MOVSB
    
    MOV AL, 0 ; Set zero terminator
    MOV [DI], AL
    
    ; Check if names match
    CMP BYTE PTR [patientName], 0
    JNE NAMES_MATCH
    
    ; Names don't match, move to the next patient
    ADD DI, 98 ; Move to the next patient data
    JMP SEARCH_LOOP
    
    NAMES_MATCH:
    ; Print the removed patient's information
    LEA SI, [patientsData+DI-2]
    LEA DI, patientName
    MOVSB
    
    LEA SI, [patientsData+DI+96]
    LEA DI, birthDate
    MOVSB
    
    LEA SI, [patientsData+DI+98]
    LEA DI, bloodGroup
    MOVSB
    
    MOV Al, [patientsData+DI+100]
    MOV condition, Al
    
    ; Remove the patient from the queue
    MOV DX, CX ; Save the patient count
    
    ; Move the subsequent patients up in the queue
    SUB DX, 1
    SUB DI, 100
    
    REMOVE_LOOP:
    MOV AL, [patientsData+DI+100]
    MOV [patientsData+DI], AL
    
    LEA SI, [patientsData+DI+102]
    LEA DI, [patientsData+DI+2]
    MOVSB
    
    LEA SI, [patientsData+DI+98]
    LEA DI, [patientsData+DI]
    MOVSB
    
    DEC DX
    JNZ REMOVE_LOOP
    
    ; Decrement the patient count
    DEC patientCount
    
    ; Print the removed patient's condition
    LEA DX, conditions
    MOV AH, 09h
    INT 21h
    
    MOV Al, condition
    ADD Al, '0' ; Convert binary value to ASCII digit
    MOV DL, AL
    MOV AH, 02h
    INT 21h
    
    ; Print newline character
    MOV DL, 0Ah
    MOV AH, 02h
    INT 21h
    
    JMP MENU
    
PATIENT_NOT_FOUND:
    ; Print patient not found message
    LEA DX, invalidInput
    MOV AH, 09h
    INT 21h
    
    JMP MENU
    
DISPLAY_WARD:


    DISPLAY_PATIENT 0
    
    
    
    
    
    JMP MENU
    
EXIT:
    ; Print the exit message
    LEA DX, exitMsg
    MOV AH, 09h
    INT 21h
    
    ; Terminate the program
    MOV AH, 4Ch
    INT 21h
    
CODE ENDS
END START



