| class | shipped | rebuilt | missing |
|---|---:|---:|---:|
| ATIR5002DContext | 13 | 5 | 8 |
| ATIR500DVDContext | 23 | 13 | 10 |
| ATIR500GLContext | 30 | 26 | 4 |
| ATIR500Memory | 8 | 8 | 0 |
| ATIR500Surface | 50 | 27 | 23 |
| ATIRadeonX1000 | 90 | 33 | 57 |
| IOATIR5002DContext | 28 | 15 | 13 |
| IOATIR500Accelerator | 69 | 28 | 41 |
| IOATIR500DVDContext | 25 | 17 | 8 |
| IOATIR500GLContext | 38 | 33 | 5 |
| IOATIR500Shared | 15 | 15 | 0 |
| IOATIR500Surface | 81 | 65 | 16 |
| **total** | **470** | **285** | **185** |

### ATIR5002DContext (8 missing)
`getTargetAndMethodForIndex`, `get_buffer_info`, `invalidate`, `load_image`, `set_destination`, `start`, `stop`, `submit_context_buffer`

### ATIR500DVDContext (10 missing)
`build_scissor`, `clientMemoryForType`, `discard_command_buffer`, `finish`, `getTargetAndMethodForIndex`, `invalidate`, `start`, `stop`, `submit_context_buffer`, `update_surface`

### ATIR500GLContext (4 missing)
`clientMemoryForType`, `setCompatibleSurfaceMode`, `set_texture_flags`, `update_surface`

### ATIR500Surface (23 missing)
`bad_panel`, `blast_key_color`, `buffer_map_offset`, `build_swap`, `calc_h_inc_step_by`, `calc_h_scaler_blank`, `copy_buffer_using_DMA`, `copy_from_buffer`, `copy_to_buffer`, `debug_read_reg_dump`, `debug_reg_dump`, `filter_init`, `filter_setup`, `get_surf_desc_regs`, `get_surface_info`, `move_overlay_xy`, `query_BIOS_for_bandwidth_info`, `real_to_hex`, `set_gamma_coefficient`, `set_linear_transform`, `setupFullScreen`, `setup_overlay_reg`, `submit_swap_buffer`

### ATIRadeonX1000 (57 missing)
`GPUSensorFunc`, `SWDSEnableCLUT`, `SWDSFunc`, `SWDSInit`, `SWDSIsRequired`, `SWDSShutdown`, `SWDSWriteBlitToCmdBuf`, `addToMinMaxGART`, `addToPCIeGART`, `callPlatformFunction`, `checkForConsumedIDCTTimeStamp`, `checkForRetiredTimeStamp`, `checkForTimeStamp`, `clearInGART`, `commitAGPMemory`, `configureAGP`, `display_mode_did_change`, `display_mode_will_change`, `free`, `getAccelCapsBits`, `getPeriodValue`, `initialize_GUI`, `initialize_hardware`, `load_promo4_micro_code`, `makeGARTEntry`, `mapVendorTransferBuffer`, `noop_buffer`, `pageOffPCIeGART`, `pageOnPCIeGART`, `releaseAGPMemory`, `removeFromGART`, `removeFromPCIeGART`, `reserveInGART`, `set_display_mode_and_vram`, `setupR520Pipes`, `setup_R500_internal_space`, `shutdownPCIeGART`, `sleepForConsumedIDCTTimeStamp`, `sleepForRetiredTimeStamp`, `sleepForTimeStampNoLock`, `start`, `start_promo4_engine`, `start_xdct_engine`, `startupPCIeGART`, `stop`, `stop_promo4_engine`, `stop_xdct_engine`, `submit_buffer_retired`, `submit_commands`, `system_did_change_speed`, `system_will_change_speed`, `teardownAGP`, `tmpTotalVRAM`, `unmapVendorTransferBuffer`, `waitForRetiredTimeStamp`, `waitForTimeStampNoLock`, `writePerformanceStats`

### IOATIR5002DContext (13 missing)
`clientClose`, `clientMemoryForType`, `create_transfer`, `get_surface_info`, `init_command_buffer_header`, `lock_memory`, `remove_surface`, `set_macrovision`, `set_surface`, `start`, `stop`, `swap_surface`, `unlock_memory`

### IOATIR500Accelerator (41 missing)
`ASICSupportsAGP`, `addToMinMaxGART`, `clearInGART`, `commitAGPMemory`, `configureAGP`, `disp_mode_did_change`, `disp_mode_will_change`, `display_change_handler`, `findFramebuffers`, `flush_memory_for_in`, `flush_memory_for_out`, `foundFramebuffer`, `freeAllCommandBuffers`, `freeAllDataBuffers`, `free_gart_wirings`, `garbage_collector`, `garbage_collector_timer`, `gart_collector`, `gart_collector_timer`, `getAccelCapsBits`, `is_idle`, `makeGARTEntry`, `mapVendorTransferBuffer`, `pageoff_dirty_texture`, `releaseAGPMemory`, `removeFromGART`, `requestProbe`, `reserveInGART`, `serializePerformanceStats`, `set_stereo`, `setup2D`, `start`, `stop`, `synchronizeGART`, `system_did_wake`, `system_will_sleep`, `teardown2D`, `teardown3D`, `teardownAGP`, `unmapVendorTransferBuffer`, `writePerformanceStats`

### IOATIR500DVDContext (8 missing)
`clientClose`, `clientMemoryForType`, `init_command_buffer_header`, `lock_all_buffers`, `remove_surface`, `setCompatibleSurfaceMode`, `start`, `stop`

### IOATIR500GLContext (5 missing)
`add_vendor_surface_required_bits`, `clientClose`, `remove_surface`, `setCompatibleSurfaceMode`, `set_texture_flags`

### IOATIR500Surface (16 missing)
`add_2d_context_to_list`, `alloc_buffer_backing_store`, `alloc_surface`, `alloc_surface_keep`, `alloc_surfaces`, `buffer_map_offset`, `clientClose`, `clientMemoryForType`, `free`, `move_buffer_from_backing_store`, `remove_2d_context_from_list`, `set_access`, `setupFullScreen`, `sleep_blocked`, `stop`, `surface_req_bits`

