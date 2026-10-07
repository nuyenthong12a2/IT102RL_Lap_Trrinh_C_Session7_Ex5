#include <stdio.h>

struct EnvironmentSensor {
    int sensor_id;
    char room_name[51];
    float temperature;
    float humidity;
    int battery_level;
};

int main(void) {
    struct EnvironmentSensor sensor;
    const char *status;

    if (scanf("%d", &sensor.sensor_id) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }
    if (scanf("%50s", sensor.room_name) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }
    if (scanf("%f", &sensor.temperature) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }
    if (scanf("%f", &sensor.humidity) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }
    if (scanf("%d", &sensor.battery_level) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }

    if (sensor.battery_level < 0 || sensor.battery_level > 100) {
        printf("Loi: Dung luong pin khong hop le!\n");
        return 0;
    }

    if (sensor.battery_level < 10 || sensor.temperature > 60.0f) {
        status = "CRITICAL";
    } else if ((sensor.battery_level >= 10 && sensor.battery_level <= 20) ||
               (sensor.temperature >= 40.0f && sensor.temperature <= 60.0f) ||
               sensor.humidity > 85.0f) {
        status = "WARNING";
    } else {
        status = "SAFE";
    }

    printf("--- HE THONG MONITORING SMART_HOME_IOT ---\n");
    printf("Ma cam bien: %d\n", sensor.sensor_id);
    printf("Phong: %s\n", sensor.room_name);
    printf("Nhiet do: %.2f C\n", sensor.temperature);
    printf("Do am: %.2f %%\n", sensor.humidity);
    printf("Dung luong pin: %d %%\n", sensor.battery_level);
    printf("Trang thai: %s\n", status);

    return 0;
}