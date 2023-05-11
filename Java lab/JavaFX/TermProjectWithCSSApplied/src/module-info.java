module TermProjectWithCSSApplied {
    requires javafx.fxml;
    requires javafx.controls;
    requires javafx.graphics;

    opens Football_DB.server;
    opens Football_DB.data;
    opens Football_DB.club;
    opens Football_DB.main;
    opens Football_DB.controller;
    opens Football_DB.club_css;
}