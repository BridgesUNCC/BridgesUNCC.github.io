/**
 *
 * Created by Kalpathi Subramanian, 2/19/18
 *
 */
#include <string>

using namespace std;

class StudentInfo {
	private:
		string studentID, fullName, program, email,
			   dislikeColor, favoriteColor;
		double studentCreditHours;

	public:
		/**
		 * @param studentID
		 * @param fullName
		 * @param program
		 * @param email
		 */
		StudentInfo() {
			studentID =  fullName = program = email =
							dislikeColor = favoriteColor = "";
			studentCreditHours = 0.0f;
		}
		StudentInfo(string studentID, string fullName, string program,
			string email, string dislikeColor, string favoriteColor,
			double studentCreditHours) {
			this->studentID = studentID;
			this->fullName = fullName;
			this->program = program;
			this->email = email;
			this->dislikeColor = dislikeColor;
			this->favoriteColor = favoriteColor;
			this->studentCreditHours = studentCreditHours;
		}

		/**
		 * @return studentID
		 */
		string getStudentID() {
			return studentID;
		}

		/**
		 * @param studentID
		 */
		void setStudentID(string studentID) {
			this->studentID = studentID;
		}

		/**
		 * @return fullName
		 */
		string getFullName() {
			return fullName;
		}

		/**
		 * @param fullName
		 */
		void setFullName(string fullName) {
			this->fullName = fullName;
		}

		/**
		 * @return program
		 */
		string getProgram() {
			return program;
		}

		/**
		 * @param program
		 */
		void setProgram(string program) {
			this->program = program;
		}

		/**
		 * @return email
		 */
		string getEmail() {
			return email;
		}

		/**
		 * @param email
		 */
		void setEmail(string email) {
			this->email = email;
		}


		/**
		 * @return favoriteColor
		 */
		string getFavoriteColor() {
			return favoriteColor;
		}

		/**
		 * @param favoriteColor
		 */
		void setFavoriteColor(string favoriteColor) {
			this->favoriteColor = favoriteColor;
		}


		string getDislikeColor() {
			return dislikeColor;
		}

		void setDislikeColor(string dislikeColor) {
			this->dislikeColor = dislikeColor;
		}

		double getStudentCreditHours() {
			return studentCreditHours;
		}

		void setStudentCreditHours(double studentCreditHours) {
			this->studentCreditHours = studentCreditHours;
		}
		string getStudentLabel() {
			string label = fullName      +  "\\n"   +
				"Email: " +            email         +  "\\n"   +
				"Program: " +            program       +  "\\n"   +
				"Student ID: " +         studentID     +  "\\n"   +
				"Favorite Color: " + favoriteColor +  "\\n";
			"Dislike Color: "
			+ dislikeColor;

			return label;
		}
};

