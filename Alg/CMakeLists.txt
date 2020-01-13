atlas_subdir( Alg )

atlas_depends_on_subdirs( PRIVATE
                    Generators/GeneratorObjects
                    Control/AthenaBaseComps
                    Tracker/TrackerSimEvent
        )

atlas_add_component( Alg
                    src/Alg.cxx
                    src/components/Alg_entries.cxx
                    LINK_LIBRARIES AthenaBaseComps GeneratorObjects TrackerSimEvent
        )

atlas_install_joboptions( share/*.py)