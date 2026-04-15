#include "tester.h"

t_result	run_cub3d(char *file)
{
	t_result	res;
	char		*argv[3] = {"./cub3D", NULL, NULL};

	bzero(&res, sizeof(t_result));
	argv[1] = file;
	exec_program(&res, argv);
	return (res);
}

Test(invalid, wrong_xpm_extension)
{
	t_result res = run_cub3d("./maps/invalid/invalid_xpm_extension.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nWrong texture file extension\n");
}

Test(invalid, file_doesnt_exist)
{
	t_result res = run_cub3d("no.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nopen: No such file or directory\n");
}

Test(invalid, empty_file)
{
	t_result res = run_cub3d("./maps/invalid/empty.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nEmpty file\n");
}

Test(invalid, no_map)
{
	t_result res = run_cub3d("./maps/invalid/no_map.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nNo map found\n");
}

Test(cub3d, wrong_extension_cubb)
{
	t_result res = run_cub3d("./maps/invalid/invalid_extension.cubbb");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid input format\n");
}


Test(invalid, no_args)
{
	t_result res = run_cub3d(0);
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid number of arguments\n");
}

Test(invalid, empty_arg)
{
	t_result res = run_cub3d("");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid input format\n");
}

Test(invalid, hidden_file_in_folder)
{
	t_result res = run_cub3d("./maps/invalid/.cub");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid input format\n");
}

Test(invalid, hidden_file)
{
	t_result res = run_cub3d(".cub");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid input format\n");
}
//to be modified to correct err_message, when bug is fixed
Test(invalid, empty_xpm_file)
{
	t_result res = run_cub3d("./maps/invalid/empty_xpm_file.cub");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nFailed to load north texture\n");
}

Test(invalid, linked_hidden_file_xpm)
{
	t_result res = run_cub3d("./maps/invalid/link_xpm_file.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nWrong texture file extension\n");
}

Test(invalid, invalid_char_in_map)
{
	t_result res = run_cub3d("./maps/invalid/invalid_char_in_map.cub");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid info in provided file\n");
}

Test(invalid, wrong_extension_txt)
{
	t_result res = run_cub3d("./maps/invalid/invalid_extension.txt");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid input format\n");
}

Test(invalid, misplaced_info)
{
	t_result res = run_cub3d("./maps/invalid/misplaced_info.cub");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid info in provided file\n");
}

Test(invalid, missing_texture)
{
	t_result res = run_cub3d("./maps/invalid/missing_texture.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nNo path found\n");
}

Test(invalid, only_map)
{
	t_result res = run_cub3d("./maps/invalid/only_map.cub");
	
	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nInvalid info in provided file\n");
}

Test(invalid, player_out_of_map)
{
	t_result res = run_cub3d("./maps/invalid/player_out_of_map.cub");
	
cr_assert_eq(res.exit_code, 1);
cr_assert_str_eq(res.stderr, "Error\nInvalid info in provided file\n");
}

Test(invalid, random_content)
{
	t_result res = run_cub3d("./maps/invalid/random_content.cub");
	
cr_assert_eq(res.exit_code, 1);
cr_assert_str_eq(res.stderr, "Error\nNo map found\n");
}

Test(invalid, space_in_colour)
{
	t_result res = run_cub3d("./maps/invalid/space_in_color.cub");
	
cr_assert_eq(res.exit_code, 1);
cr_assert_str_eq(res.stderr, "Error\nInvalid colour description\n");
}

Test(invalid, space_in_map)
{
	t_result res = run_cub3d("./maps/invalid/space_in_map.cub");
	
cr_assert_eq(res.exit_code, 1);
cr_assert_str_eq(res.stderr, "Error\nEmpty line in map\n");
}

Test(invalid, multiple_maps)
{
	t_result res = run_cub3d("./maps/invalid/multiple_maps.cub");
	
cr_assert_eq(res.exit_code, 1);
cr_assert_str_eq(res.stderr, "Error\nEmpty line in map\n");
}
