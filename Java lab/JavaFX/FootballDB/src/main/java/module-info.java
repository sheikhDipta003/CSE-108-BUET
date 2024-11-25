module com.sheikhdipta003.footballdb {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;

    opens com.sheikhdipta003.footballdb.main to javafx.fxml;
    opens com.sheikhdipta003.footballdb.controller to javafx.fxml;
    opens com.sheikhdipta003.footballdb.club_css;
    opens com.sheikhdipta003.footballdb.club_fxml;
    exports com.sheikhdipta003.footballdb.main;
    opens com.sheikhdipta003.footballdb.data to javafx.base;
}

