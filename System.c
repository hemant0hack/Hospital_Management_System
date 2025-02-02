#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures for Patient, Doctor, and Appointment
typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
    char disease[100];
    char admissionDateTime[30];
} Patient;

typedef struct {
    int id;
    char name[100];
    char specialization[100];
    int experience;
} Doctor;

typedef struct {
    int id;
    int patientId;
    int doctorId;
    char appointmentDateTime[30];
} Appointment;

// Declare arrays and counters for storing records
Patient patients[100];
Doctor doctors[100];
Appointment appointments[100];
int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;

// Function to get the current date and time
void getCurrentDateTime(char* buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d-%02d-%d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Function to add a new patient
void addPatient() {
    printf("Enter Patient ID: ");
    scanf("%d", &patients[patientCount].id);
    printf("Enter Patient Name: ");
    scanf("%s", patients[patientCount].name);
    printf("Enter Patient Age: ");
    scanf("%d", &patients[patientCount].age);
    printf("Enter Patient Gender: ");
    scanf("%s", patients[patientCount].gender);
    printf("Enter Patient Disease: ");
    scanf("%s", patients[patientCount].disease);
    getCurrentDateTime(patients[patientCount].admissionDateTime);
    patientCount++;
    printf("Patient added successfully!\n");
}

// Function to view all patients
void viewPatients() {
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Disease: %s, Admission DateTime: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease, patients[i].admissionDateTime);
    }
}

// Function to delete a patient by ID
void deletePatient() {
    int id;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient deleted successfully!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

// Function to add a new doctor
void addDoctor() {
    printf("Enter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].id);
    printf("Enter Doctor Name: ");
    scanf("%s", doctors[doctorCount].name);
    printf("Enter Doctor Specialization: ");
    scanf("%s", doctors[doctorCount].specialization);
    printf("Enter Doctor Experience (years): ");
    scanf("%d", &doctors[doctorCount].experience);
    doctorCount++;
    printf("Doctor added successfully!\n");
}

// Function to view all doctors
void viewDoctors() {
    for (int i = 0; i < doctorCount; i++) {
        printf("ID: %d, Name: %s, Specialization: %s, Experience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
    }
}

// Function to delete a doctor by ID
void deleteDoctor() {
    int id;
    printf("Enter Doctor ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            for (int j = i; j < doctorCount - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            doctorCount--;
            printf("Doctor deleted successfully!\n");
            return;
        }
    }
    printf("Doctor not found!\n");
}

// Function to add a new appointment
void addAppointment() {
    printf("Enter Appointment ID: ");
    scanf("%d", &appointments[appointmentCount].id);
    printf("Enter Patient ID: ");
    scanf("%d", &appointments[appointmentCount].patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &appointments[appointmentCount].doctorId);
    getCurrentDateTime(appointments[appointmentCount].appointmentDateTime);
    appointmentCount++;
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void viewAppointments() {
    for (int i = 0; i < appointmentCount; i++) {
        printf("ID: %d, Patient ID: %d, Doctor ID: %d, Appointment DateTime: %s\n", appointments[i].id, appointments[i].patientId, appointments[i].doctorId, appointments[i].appointmentDateTime);
    }
}

// Main function to display the menu and handle user choices
int main() {
    int choice;
    while (1) {
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Delete Patient\n");
        printf("4. Add Doctor\n");
        printf("5. View Doctors\n");
        printf("6. Delete Doctor\n");
        printf("7. Add Appointment\n");
        printf("8. View Appointments\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                deletePatient();
                break;
            case 4:
                addDoctor();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                deleteDoctor();
                break;
            case 7:
                addAppointment();
                break;
            case 8:
                viewAppointments();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}