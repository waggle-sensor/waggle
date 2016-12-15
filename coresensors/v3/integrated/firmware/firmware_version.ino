//** 
//** CORESENSE FIRMWARE VERSION
//**
#ifdef VERSION_INCLUDE

#include "verinfo.cpp"
#include "buildinfo.cpp"

void hw_sw_version_buffer(void)
{
	uint16_t version_int = 0;
	uint8_t first_byte = CORESENSE_HW_VER_MAJ << 5 | (CORESENSE_HW_VER_MIN & 0x07) << 2 | (CORESENSE_KERNEL_MAJ & 0x0F) >> 2;
	uint8_t second_byte = (CORESENSE_KERNEL_MAJ & 0x0F) << 6 | (CORESENSE_KERNEL_MIN * 10 + CORESENSE_KERNEL_SUB) & 0x3F;
	// uint8_t second_byte = CORESENSE_KERNEL_MAJ << 5 | 0 << 4 | 1 << 3 | 1 << 2 | 1 << 1

	version_int = first_byte << 8 | second_byte & 0xff;

	format1(version_int);
	FIRMWARE_VERSION[2] = formatted_data_buffer[0];
	FIRMWARE_VERSION[3] = formatted_data_buffer[1];

}

void build_time_buffer(void)
{
	formatted_data_buffer[0] = (BUILD_TIME & 0xff000000) >> 24;
    formatted_data_buffer[1] = (BUILD_TIME & 0xff0000) >> 16;
    formatted_data_buffer[2] = (BUILD_TIME & 0xff00) >> 8;
    formatted_data_buffer[3] = (BUILD_TIME & 0xff);

    FIRMWARE_VERSION[4] = formatted_data_buffer[0];
    FIRMWARE_VERSION[5] = formatted_data_buffer[1];
    FIRMWARE_VERSION[6] = formatted_data_buffer[2];
    FIRMWARE_VERSION[7] = formatted_data_buffer[3];
}

void build_git_buffer(void)
{
	uint16_t buildinfo_git = (int) strtol(BUILD_GIT, 0, 16);

	format1(buildinfo_git);
	FIRMWARE_VERSION[8] = formatted_data_buffer[0];
    FIRMWARE_VERSION[9] = formatted_data_buffer[1];
}

void version_info(void)
{
	hw_sw_version_buffer();
	build_time_buffer();
	build_git_buffer();
}
#endif