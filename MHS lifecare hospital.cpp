#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base Class
class Hospital {
protected:
    string hospitalName, address, contact;
public:
    Hospital() {
        hospitalName = "MHS Lifecare";
        address = "123 Health Street, Wellness City";
        contact = "+91 98765 43210";
    }
    void showHospitalDetails() {
        cout << "\nWelcome to " << hospitalName << "!\n";
        cout << "Address: " << address << "\n";
        cout << "Contact: " << contact << "\n";
        cout << "Departments: Cardiology, Neurology, Orthopedics, Pediatrics, General Medicine\n";
    }
    void showEmergencyServices() {
        cout << "\nEmergency Services:\n- 24/7 Ambulance\n- Trauma Care\n- ICU\n";
    }
    void showSpecialFacilities() {
        cout << "\nSpecial Facilities:\n- Free Health Checkups on Sundays\n- Online Consultations Available\n- Discounted Medicines for Senior Citizens\n";
    }
};

// Doctor Class
class Doctor : public Hospital {
private:
    string docName, specialization;
    int experience;
public:
    Doctor(string name, string spec, int exp) {
        docName = name;
        specialization = spec;
        experience = exp;
    }
    void showDoctor() {
        cout << "Doctor: " << docName << " | Specialization: " << specialization << " | Experience: " << experience << " years\n";
    }
};

// Patient Class
class Patient : public Hospital {
private:
    string name, disease;
    int age;
public:
    Patient(string pName, string pDisease, int pAge) {
        name = pName;
        disease = pDisease;
        age = pAge;
    }
    void showPatient() {
        cout << "Patient Name: " << name << " | Age: " << age << " | Disease: " << disease << "\n";
    }
    friend void saveToFile(Patient &p);
};

// File Handling Function
void saveToFile(Patient &p) {
    ofstream file("patients.txt", ios::app);
    file << "Name: " << p.name << ", Age: " << p.age << ", Disease: " << p.disease << "\n";
    file.close();
    cout << "Patient details saved successfully!\n";
}

// Appointment Class
class Appointment {
private:
    string patientName, doctorName, date, time;
public:
    Appointment(string pName, string dName, string appDate, string appTime) {
        patientName = pName;
        doctorName = dName;
        date = appDate;
        time = appTime;
    }
    void showAppointment() {
        cout << "Appointment: " << patientName << " has an appointment with Dr. " << doctorName << " on " << date << " at " << time << "\n";
    }
};

// Feedback system
void collectFeedback() {
    string feedback;
    cout << "\nWrite your feedback: ";
    getline(cin, feedback);
    ofstream fb("feedback.txt", ios::app);
    fb << "Feedback: " << feedback << "\n";
    fb.close();
    cout << "Thanks for your feedback!\n";
}

// Rating system
void rateDoctor() {
    int rating;
    cout << "\nRate your doctor (1 to 5): ";
    cin >> rating;
    if (rating >= 1 && rating <= 5)
        cout << "You rated the doctor " << rating << " stars!\n";
    else
        cout << "Invalid rating.\n";
}

// Health Tip
void showHealthTip() {
    cout << "\nHealth Tip: Drink plenty of water and stay active!\n";
}

int main() {
    Hospital hosp;
    int choice;

    do {
        cout << "\n*** MHS Lifecare Menu ***\n";
        cout << "1. Add Doctor\n2. Add Patient\n3. Schedule Appointment\n4. View Hospital Details\n5. Emergency Services\n6. Special Facilities\n7. Leave Feedback\n8. Rate Doctor\n9. Health Tip\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string name, spec;
                int exp;
                cout << "Doctor Name: "; getline(cin, name);
                cout << "Specialization: "; getline(cin, spec);
                cout << "Experience (years): "; cin >> exp;
                Doctor doc(name, spec, exp);
                doc.showDoctor();
                break;
            }
            case 2: {
                string name, disease;
                int age;
                cout << "Patient Name: "; getline(cin, name);
                cout << "Age: "; cin >> age; cin.ignore();
                cout << "Disease: "; getline(cin, disease);
                Patient pat(name, disease, age);
                pat.showPatient();
                saveToFile(pat);
                break;
            }
            case 3: {
                string pName, dName, date, time;
                cout << "Patient Name: "; getline(cin, pName);
                cout << "Doctor Name: "; getline(cin, dName);
                cout << "Date: "; getline(cin, date);
                cout << "Time: "; getline(cin, time);
                Appointment app(pName, dName, date, time);
                app.showAppointment();
                break;
            }
            case 4:
                hosp.showHospitalDetails();
                break;
            case 5:
                hosp.showEmergencyServices();
                break;
            case 6:
                hosp.showSpecialFacilities();
                break;
            case 7:
                collectFeedback();
                break;
            case 8:
                rateDoctor();
                break;
            case 9:
                showHealthTip();
                break;
            case 10:
                cout << "\nThank you for visiting MHS Lifecare. Stay healthy!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 10);

    return 0;
}

