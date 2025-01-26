#![no_std]
#![no_main]

mod writer;
use core::fmt::Write;
use bootloader_api::config::Mapping;
use x86_64::instructions::hlt;
use writer::FrameBufferWriter;

#[panic_handler]
fn panic(_info: &core::panic::PanicInfo) -> ! {
    loop {
        hlt();
    }
}


// Use the entry_point macro to register the entry point function:
// bootloader_api::entry_point!(kernel_main)
// Optionally pass a custom config
pub static BOOTLOADER_CONFIG: bootloader_api::BootloaderConfig = {
    let mut config = bootloader_api::BootloaderConfig::new_default();
    config.mappings.physical_memory = Some(Mapping::Dynamic);
    config.kernel_stack_size = 100 * 1024; // 100 KiB
    config
};

bootloader_api::entry_point!(my_entry_point, config = &BOOTLOADER_CONFIG);

fn my_entry_point(boot_info: &'static mut bootloader_api::BootInfo) -> ! {
    let frame_buffer_info = boot_info.framebuffer.as_mut().unwrap().info();
    let buffer = boot_info.framebuffer.as_mut().unwrap().buffer_mut();
    let mut frame_buffer_writer = FrameBufferWriter::new(buffer, frame_buffer_info);

    // Write some text at the default position (top-left corner)
    writeln!(frame_buffer_writer, "Starting at the top-left corner...").unwrap();

    // Set the cursor to a new position (e.g., x = 500, y = 50)
    frame_buffer_writer.set_cursor_position(500, 70);
    writeln!(frame_buffer_writer, "Writing at position (500, 70)...").unwrap();
     
    // Write more text, which will continue from the new cursor position
    writeln!(frame_buffer_writer, "This text follows the previous line.").unwrap();

    // Test screen scrolling by writing multiple lines
    for i in 0..5 {
        writeln!(frame_buffer_writer, "Line {}: Testing screen scrolling...", i).unwrap();
    }


    // Set the cursor to a position near the bottom of the screen
    frame_buffer_writer.set_cursor_position(500, frame_buffer_info.height - 50 );
    writeln!(frame_buffer_writer, "Writing near the bottom of the screen...").unwrap();

    // Loop forever to keep the kernel running
    loop {
        hlt(); // Stop x86_64 from being unnecessarily busy while looping
    }
}