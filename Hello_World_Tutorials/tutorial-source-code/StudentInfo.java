public class StudentInfo {
	private String studentID, fullName, program, email, dislikeColor, favoriteColor, avatar;
	private double studentCreditHours;

	public StudentInfo(String studentID, String fullName, String program, String email, String dislikeColor,
			String favoriteColor, double studentCreditHours, String avatar) {
		this.studentID = studentID;
		this.fullName = fullName;
		this.program = program;
		this.email = email;
		this.dislikeColor = dislikeColor;
		this.favoriteColor = favoriteColor;
		this.studentCreditHours = studentCreditHours;
		this.avatar = avatar;
	}
	public String getStudentID() {
		return studentID;
	}
	public void setStudentID(String studentID) {
		this.studentID = studentID;
	}
	public String getFullName() {
		return fullName;
	}
	public void setFullName(String fullName) {
		this.fullName = fullName;
	}
	public String getProgram() {
		return program;
	}
	public void setProgram(String program) {
		this.program = program;
	}

	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getFavoriteColor() {
		return favoriteColor;
	}
	public void setFavoriteColor(String favoriteColor) {
		this.favoriteColor = favoriteColor;
	}
	public String getAvatar() {
		return avatar;
	}
	public void setAvatar(String avatar) {
		this.avatar = avatar;
	}
	public String getDislikeColor() {
		return dislikeColor;
	}
	public void setDislikeColor(String dislikeColor) {
		this.dislikeColor = dislikeColor;
	}
	public double getStudentCreditHours() {
		return studentCreditHours;
	}
	public void setStudentCreditHours(double studentCreditHours) {
		this.studentCreditHours = studentCreditHours;
	}
}