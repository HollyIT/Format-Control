**** IMPORTANT NOTE REGARDING THE STATUS OF THIS PROJECT ****

This is a fork of Better Formats:
http://drupal.org/project/better_formats

This fork incorporates the per field and per entity type settings for better format control, as
defined in this patch:

http://drupal.org/node/1275266

I hope to get these features added into Better Formats so that this module isn't needed.

**** ADDED FEATURES OVER BETTER FORMATS ****

Format Control also adds in new permissions to view the /filter/tips page, instead of it
being publicly accessible at all times. 

If you have CTools installed, then Format Control will display the filtering tips in a 
dialog window and show the tips for the current input format you have selected.

**** TO USE ****

Once the module is enabled, head over to /admin/config/content/formats/settings. Select an entity
type that you wish to add a default format configuration for. You can drag and drop the formats to the
order you wish. The top format allowed by the user will become the default. Checking the disable checkbox
will prevent that format from being used on the entity type.

To define per field settings, edit the desired text field. Text processing must be enabled in order
to set format options. If it is not enabled, then select text processing and save the form. After that
go back and edit it and the options table will appear.

Setting per field options is the same as setting the per entity type options, with the exception of the
override checkbox. You must enable this checkbox in order to have this field's formats override.

There are other settings available for each configuration. They are:

- Show formatting tips: This will show the formatting tips on the field
- Show More Tips Link: Click to show the "More information about text formats" link.
- Show More Tips In A Popup Dialog: If you have the CTools module installed then the filtering tips
  will appear in a popup dialog window.
